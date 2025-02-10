#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <fstream>

const int MAX_ATTEMPTS = 3;

std::string hash_password(const std::string &password) {
    // Use a secure hashing algorithm to hash the password (e.g. bcrypt, scrypt, Argon2, etc.)
    // Example implementation using the SHA-256 algorithm:
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password.c_str(), password.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

bool verify_password(const std::string &username, const std::string &password) {
    // Open the file containing the hashed passwords
    std::ifstream file("hashed_passwords.txt");
    std::string line;
    while (std::getline(file, line)) {
        // Split the line into the username and hashed password
        size_t delimiter_pos = line.find(':');
        std::string file_username = line.substr(0, delimiter_pos);
        std::string file_hashed_password = line.substr(delimiter_pos + 1);
        if (file_username == username) {
            // Compare the entered password with the hashed password from the file
            return hash_password(password) == file_hashed_password;
        }
    }
    // Return false if the username was not found in the file
    return false;
}

int main() {
    std::cout << "Login\n";
    std::cout << "Enter username: ";
    std::string username;
    std::cin >> username;
    std::cout << "Enter password: ";
    std::string password;
    std::cin >> password;
    int attempts = 0;
    while (!verify_password(username, password) && attempts < MAX_ATTEMPTS) {
        std::cout << "Incorrect username or password. Try again.\n";
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;
        attempts++;
    }
    if (attempts == MAX_ATTEMPTS) {
        std::cout << "Too many attempts. Access denied.\n";
        return 1;
    }
    std::cout << "Access granted.\n";
    return 0;
}

