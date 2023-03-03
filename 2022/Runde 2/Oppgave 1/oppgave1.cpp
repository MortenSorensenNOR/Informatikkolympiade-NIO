#include <iostream>

int main() {
    std::string key;
    std::string message_length;
    std::string message;
    std::getline(std::cin, key);
    std::getline(std::cin, message_length);
    std::getline(std::cin, message);

    std::string output = "";
    for (int i = 0; i < std::stoi(message_length); i++) {
        int n = key.find(message[i]);
        n = (n + 25) % 26;
        output.push_back(key[n]);
    }
    
    std::cout << output;

    return 0;
}