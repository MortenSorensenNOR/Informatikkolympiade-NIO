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
    string line;
    ifstream data_file;
    string path = "day6.txt";
    data_file.open(path);

    if (data_file.is_open())
    {
        // Read Create Stack Data
        int len = 14;
        while(getline(data_file, line))
        {
            int n = 0;
            for (int i = 0; i < line.size() - len; i++)
            {
                set<char> s;
                for (int j = 0; j < len; j++)
                {
                    s.insert(line.c_str()[i+j]);
                }
                if (s.size() == len)
                    break;
                n++;
            }
            printf("%d\n", n+len);
        }
    }
    else 
    {
        printf("No such file found");
    }
    return 0;
}