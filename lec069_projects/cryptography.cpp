#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a plaintext using Caesar cipher
string encryptCaesar(string plaintext, int shift) {
    string encrypted = "";

    for (char c : plaintext) {
        if (isalpha(c)) { // Check if character is a letter
            char base = islower(c) ? 'a' : 'A'; // Determine if it is lowercase or uppercase
            char encryptedChar = (c - base + shift) % 26 + base;
            encrypted += encryptedChar;
        } else {
            encrypted += c; // Non-alphabet characters are added unchanged
        }
    }

    return encrypted;
}

// Function to decrypt a ciphertext using Caesar cipher
string decryptCaesar(string ciphertext, int shift) {
    return encryptCaesar(ciphertext, 26 - (shift % 26)); // Decrypt by shifting in the opposite direction
}

int main() {
    string plaintext;
    int shift;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the shift value: ";
    cin >> shift;

    string encrypted = encryptCaesar(plaintext, shift);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decryptCaesar(encrypted, shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
