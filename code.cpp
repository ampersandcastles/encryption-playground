#include <iostream>
#include <string>

// Function to perform Caesar cipher encryption
std::string encrypt(const std::string& text, int shift) {
    std::string result = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            char base = (isupper(ch)) ? 'A' : 'a';
            result += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            result += ch;
        }
    }
    return result;
}

// Function to perform Caesar cipher decryption
std::string decrypt(const std::string& text, int shift) {
    // Decryption is just encryption with a negative shift
    return encrypt(text, -shift);
}

int main() {
    std::string input;
    int shift;

    // Get user input
    std::cout << "Enter text to encrypt/decrypt: ";
    std::getline(std::cin, input);

    std::cout << "Enter shift value: ";
    std::cin >> shift;

    // Encrypt the input text
    std::string encryptedText = encrypt(input, shift);
    std::cout << "Encrypted text: " << encryptedText << "\n";

    // Decrypt the encrypted text
    std::string decryptedText = decrypt(encryptedText, shift);
    std::cout << "Decrypted text: " << decryptedText << "\n";

    return 0;
}
