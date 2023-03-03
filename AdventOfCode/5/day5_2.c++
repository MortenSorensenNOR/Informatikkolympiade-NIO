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
    int n = 9;
    vector<vector<char>> stacks(n);

    string line;
    ifstream data_file;
    string path = "day5.txt";
    data_file.open(path);

    if (data_file.is_open())
    {
        // Read Create Stack Data
        while(getline(data_file, line))
        {
            if (isdigit(line[1]))
                break;
            
            int idx = 1;
            for (int i = 0; i < n; i++)
            {
                char ch = line.c_str()[idx + 4 * i];
                if (ch != ' ')
                    stacks[i].push_back(ch);
            }
        }

        for ( auto &a : stacks )
            reverse( a.begin(), a.end() );

        getline(data_file, line);
        while(getline(data_file, line))
        {
            int num, src, dst;
            sscanf(line.c_str(), "move %d from %d to %d", &num, &src, &dst);
            src--; dst--;

            for (int i = 0; i < num; i++)
            {
                stacks[dst].push_back(*(stacks[src].end() - num + i));
            }
            stacks[src].erase(stacks[src].end() - num, stacks[src].end());

            for (int i = 0; i < n; i++)
            {
                printf("%c", stacks[i].back());
            }
            printf("\n");
        }
        printf("Solution 2: ");
        for (int i = 0; i < n; i++)
        {
            printf("%c", stacks[i].back());
        }
    }
    else 
    {
        printf("No such file found");
    }
    return 0;
}