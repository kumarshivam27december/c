#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

string sha256(const string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)input.c_str(), input.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class Transaction {
public:
    string sender, receiver;
    double amount;
    Transaction(string s, string r, double a) : sender(s), receiver(r), amount(a) {}
    string toString() const { return sender + receiver + to_string(amount); }
};

class Block {
public:
    int index;
    string prevHash, hash, merkleRoot;
    time_t timestamp;
    vector<Transaction> transactions;
    int nonce;
    
    Block(int idx, const string &prev, vector<Transaction> txs)
        : index(idx), prevHash(prev), transactions(txs), nonce(0) {
        timestamp = time(nullptr);
        merkleRoot = computeMerkleRoot();
        hash = mineBlock();
    }

    string computeMerkleRoot() {
        vector<string> hashes;
        for (auto &tx : transactions) hashes.push_back(sha256(tx.toString()));
        while (hashes.size() > 1) {
            vector<string> newHashes;
            for (size_t i = 0; i < hashes.size(); i += 2) {
                string combined = hashes[i] + (i + 1 < hashes.size() ? hashes[i + 1] : "");
                newHashes.push_back(sha256(combined));
            }
            hashes = newHashes;
        }
        return hashes.empty() ? "" : hashes[0];
    }
    
    string mineBlock(int difficulty = 4) {
        string target(difficulty, '0');
        do {
            nonce++;
            hash = sha256(toString());
        } while (hash.substr(0, difficulty) != target);
        return hash;
    }

    string toString() const {
        return to_string(index) + prevHash + merkleRoot + to_string(timestamp) + to_string(nonce);
    }
};

class Blockchain {
public:
    vector<Block> chain;
    Blockchain() { chain.emplace_back(Block(0, "0", {})); }
    void addBlock(vector<Transaction> transactions) {
        chain.emplace_back(Block(chain.size(), chain.back().hash, transactions));
    }
    void display() {
        for (auto &block : chain) {
            cout << "Block " << block.index << "\nHash: " << block.hash
                 << "\nPrevious Hash: " << block.prevHash
                 << "\nMerkle Root: " << block.merkleRoot << "\n\n";
        }
    }
};

int main() {
    Blockchain myCoin;
    myCoin.addBlock({Transaction("Alice", "Bob", 50), Transaction("Bob", "Charlie", 25)});
    myCoin.addBlock({Transaction("Charlie", "Dave", 10)});
    myCoin.display();
    return 0;
}
