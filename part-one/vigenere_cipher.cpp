// vigenere_cipher.cpp
// Encrypting and decrypting the Vigenere cipher.
#include "cipher.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string plainText;
    cout << "Enter the text to encrypt:\n";
    getline(cin, plainText);

    string secretKey;
    cout << "\nEnnter the secret key:\n";
    getline(cin, secretKey);

    Cipher cipher;

    // encrypt plainText using secretKey
    string cipherText{cipher.encrypt(plainText, secretKey)};
    cout << "\nEncrypted:\n " << cipherText << '\n';

    //decrypt cipherText
    cout << "\nDecrypted:\n "
        << cipher.decrypt(cipherText, secretKey) << '\n';

    // decrypt ciphertext entered by the user
    cout << "\nEnter the ciphertext to decipher:\n";
    getline(cin, cipherText);
    cout << "\nDecrypted:\n "
        << cipher.decrypt(cipherText, secretKey) << '\n';
}
