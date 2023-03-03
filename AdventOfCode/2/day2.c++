#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> read_file()
{
    vector<pair<int, int>> rounds;

    string line;
    ifstream data_file;
    string path = "day2.txt";
    data_file.open(path);

    if (data_file.is_open())
    {
        while(getline(data_file, line))
        {
            int o = line[0]-64, m = line[2]-87;
            rounds.push_back(make_pair(o, m));
        }
    }

    return rounds;
}

int main()
{
    bool normal = false;
    
    int score;
    vector<pair<int, int>> rounds = read_file();
    for (auto& r : rounds)
    {
        if (normal)
        {   
            if (r.first == r.second)
                score += 3;
            else if ((r.first + 1)%3 == r.second%3)
                score += 6;
            score += r.second;
        }
        else 
        {
            // X(1) == Lose || Y(2) == Draw || Z(3) == Win
            // 1 -> 3 || 2 -> 1 || 3 -> 2
            if (r.second == 1)
                score += (r.first + 1)%3 + 1;
            if (r.second == 2)
                score += r.first + 3;
            // 1 -> 2 || 2 -> 3 || 3 -> 1
            if (r.second == 3)
                score += (r.first)%3 + 7;
        }
    }
    printf("Total score: %d", score);
    return 0;
}