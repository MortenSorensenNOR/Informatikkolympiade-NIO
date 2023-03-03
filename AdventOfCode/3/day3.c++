#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<string> read_file()
{
    vector<string> backpacks;

    string line;
    ifstream data_file;
    string path = "day3.txt";
    data_file.open(path);
    if (data_file.is_open())
    {
        while(getline(data_file, line))
        {
            backpacks.push_back(line.c_str());
        }
    }

    return backpacks;
}

int main()
{
    vector<char> miss;
    vector<string> backpacks = read_file();
    for (int i = 0; i < backpacks.size(); i++)
    {
        unordered_map<char, bool> ref;
        for (int j = 0; j < backpacks[i].size() / 2; j++)
        {
            ref[backpacks[i][j]] = true;
        }
        for (int j = backpacks[i].size() / 2; j < backpacks[i].size(); j++)
        {
            if (ref.find(backpacks[i][j]) != ref.end())
            {
                miss.push_back(backpacks[i][j]);
                break;
            }
        }
    }
    int tot = 0;
    for (int i = 0; i < miss.size(); i++)
    {
        if (int(miss[i]) > 96)
            tot += int(miss[i])-96;
        else
            tot += int(miss[i])-64 + 26;
    }
    printf("Sum missplaced: %d\n", tot);

    vector<char> badges;
    for (int i = 0; i < backpacks.size(); i+=3)
    {
        unordered_map<char, bool[3]> b;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < backpacks[i+j].size(); k++)
            {
                b[backpacks[i+j][k]][j] = true;
            }
        }
        for (auto i : b)
        {
            if (i.second[0] && i.second[1] && i.second[2])
                badges.push_back(i.first);
        }
    }

    int b_tot = 0;
    for (int i = 0; i < badges.size(); i++)
    {
        if (int(badges[i]) > 96)
            b_tot += int(badges[i])-96;
        else
            b_tot += int(badges[i])-38;
    }
    printf("Sum badges: %d\n", b_tot);

    return 0;
}