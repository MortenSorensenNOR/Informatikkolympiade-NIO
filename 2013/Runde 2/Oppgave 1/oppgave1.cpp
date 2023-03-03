#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <bits/stdc++.h>

std::vector<std::string> splitStringBySpace(std::string input) {
    std::stringstream ss(input);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> splitString(begin, end);

    return splitString;
}

std::vector<int> getInput() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> splitString = splitStringBySpace(input);

    std::vector<int> output;
    for (int i = 0; i < splitString.size(); i++) {
        output.push_back(std::stoi(splitString[i]));
    }

    return output;
}

int main()
{
    std::vector<int> setup = getInput();

    std::vector<int> gjetninger;
    for (int i = 0; i < setup[1]; i++)
    {
        std::string input;
        std::cin >> input;
        gjetninger.push_back(stoi(input));
    }

    for (int i = 0; i < gjetninger.size(); i++)
    {
        if (gjetninger[i] == setup[0])
            std::cout << "RIKTIG\n";
        else if (gjetninger[i] > setup[0])
            std::cout << "FOR MYE\n";
        else 
            std::cout << "FOR LITE\n";
    }
}