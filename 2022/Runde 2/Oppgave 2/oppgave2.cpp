#include <iostream>
#include <vector>
#include <algorithm>
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

bool sortByDate(const std::vector<int> &a, const std::vector<int> &b) {
    return (a[2] < b[2]);
}

int main() {
    // Input
    std::vector<int> init = getInput();
    int N = init[0], M = init[1], I = init[2], S = init[3];
    
    std::vector<std::vector<int>> inter;
    for (int i = 0; i < M; i++) {
        std::vector<int> interaction = getInput();
        inter.push_back(interaction);        
    }
    sort(inter.begin(), inter.end(), sortByDate);

    // Program
    int p[N];
    for (int person = 0; person < N; person++) {
        p[person] = -1;
    }
    p[0] = 0;

    for (int i = 0; i < M; i++) {
        int A = inter[i][0], B = inter[i][1], D = inter[i][2];

        if (p[A] != -1 && p[A] + I <= D && p[A] + I + S > D) {
            if (p[B] == -1) p[B] = D;
        }

        if (p[B] != -1 && p[B] + I <= D && p[B] + I + S > D) {
            if (p[A] == -1) p[A] = D;
        }
    }

    // Find max number of sick
    int maxNumberOfSick = 0;
    int currentMaxSick = 0;

    std::vector<int> start;
    std::vector<int> end;
    for (int i = 0; i < N; i++) {
        if (p[i] != -1) {
            start.push_back(p[i] + I);
            end.push_back(p[i] + I + S);
        }
    }

    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());

    int i = 0;
    int j = 0;
    int m = start.size(), n = end.size();
    while(i < m && j < n) {
        if (start[i] < end[j]) {
            currentMaxSick++;
            maxNumberOfSick = (maxNumberOfSick < currentMaxSick) ? currentMaxSick : maxNumberOfSick;
            i++;
        } else {
            currentMaxSick--;
            j++;
        }
    }

    std::cout << maxNumberOfSick;
}