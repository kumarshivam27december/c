#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>

using namespace std;

string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

struct Block {
    int index;
    time_t timestamp;
    string data;
    string previousHash;
    string hash;

    Block(int idx, string data, string prevHash) {
        this->index = idx;
        this->timestamp = time(0);
        this->data = data;
        this->previousHash = prevHash;
        this->hash = calculateHash();
    }

    string calculateHash() {
        stringstream ss;
        ss << index << timestamp << data << previousHash;
        return sha256(ss.str());
    }
};

class Blockchain {
public:
    vector<Block> chain;

    Blockchain() {
        chain.push_back(createGenesisBlock());
    }

    Block createGenesisBlock() {
        return Block(0, "Genesis Block", "0");
    }

    void addBlock(string data) {
        Block newBlock(chain.size(), data, chain.back().hash);
        chain.push_back(newBlock);
    }

    void printChain() {
        for (Block block : chain) {
            cout << "Index: " << block.index << endl;
            cout << "Timestamp: " << block.timestamp << endl;
            cout << "Data: " << block.data << endl;
            cout << "Previous Hash: " << block.previousHash << endl;
            cout << "Hash: " << block.hash << endl;
            cout << "--------------------------------------" << endl;
        }
    }
};

int main() {
    Blockchain myBlockchain;
    myBlockchain.addBlock("First transaction");
    myBlockchain.addBlock("Second transaction");
    myBlockchain.printChain();
    return 0;
}
