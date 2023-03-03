#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> read_file()
{
    int i = 0;
    unordered_map<int, int> elfs;

    string line;
    ifstream data_file;
    string path = "day1.txt";
    data_file.open(path);

    if (data_file.is_open())
    {
        while(getline(data_file, line))
        {
            if (line.empty())
            {
                i++;
                elfs[i] = 0;
            } else 
            {
                elfs[i] += stoi(line.c_str());
            }
        }
    }

    return elfs;
}

int main()
{
    int fst;
    int scd;
    int thr;
    unordered_map<int, int> a = read_file();
    for (auto& elf : a)
    {
        if (elf.second > fst)
            fst = elf.second; 
        else if (elf.second > scd)
            scd = elf.second; 
        else if (elf.second > thr)
            thr = elf.second; 
    }
    printf("Top 3 sum is %d", fst + scd + thr);
    return 0;
}
