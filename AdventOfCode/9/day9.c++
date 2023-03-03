#include <set>
#include <stack>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <unordered_map>

using namespace std;

int main()
{  
    int temp_int;
    char temp_char;
    vector<pair<char, int>> data;

    string line;
    ifstream data_file;
    data_file.open("day9_test.txt");

    while(getline(data_file, line))
    {
        sscanf(line.c_str(), "%c %d", &temp_char, &temp_int);
        data.push_back(make_pair(temp_char, temp_int));
    }

    for (int i = 0; i < data.size(); i++)
    {
        printf("Char: %c, Num: %d\n", data[i].first, data[i].second);
    }


    return 0;
}