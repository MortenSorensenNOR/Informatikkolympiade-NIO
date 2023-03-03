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
    const int n = 99;
    array<int, n*n> h;
    array<bool, n*n> c;

    string line;
    ifstream data_file;
    data_file.open("day8.txt");

    int y = 0;
    while(getline(data_file, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            h[i + y * n] = stoi(&line.substr(i, 1)[0]);
            c[i + y * n] = false;
        }
        y++;
    }
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // Initialize hidden to false
            bool u = false, d = false, l = false, r = false;
            
            // Up
            for (int i = 0; i < y; i++)
                if (h[x + n * i] >= h[x + n * y])
                {
                    u = true;
                    break;
                }

            // Down
            for (int i = n-1; i > y; i--)
                if (h[x + n * i] >= h[x + n * y])
                {
                    d = true;
                    break;
                }
            
            // Left
            for (int i = 0; i < x; i++)
                if (h[i + n * y] >= h[x + n * y])
                {
                    l = true;
                    break;
                }
            
            // Right
            for (int i = n-1; i > x; i--)
                if (h[i + n * y] >= h[x + n * y])
                {
                    r = true;
                    break;
                }
            
            if (u && d && l && r) // x != 0 && x != n-1 && y != 0 && y != n-1
                c[x + n * y] = true;
        }
    }

    int total_visible = 0;
    for (int i = 0; i < c.size(); i++)
    {
        if (!c[i])
            total_visible++;
    }
    printf("Total visible: %d\n", total_visible);


    // Part 2
    int best_view = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            // Up
            int up = 0;
            for (int i = y-1; i >= 0; i--)
            {
                up++;
                if (h[x + n * i] >= h[x + n * y])
                    break;
            }

            // Down
            int down = 0;
            for (int i = y+1; i < n; i++)
            {
                down++;
                if (h[x + n * i] >= h[x + n * y])
                    break;
            }

            // Left
            int left = 0;
            for (int i = x-1; i >= 0; i--)
            {
                left++;
                if (h[i + n * y] >= h[x + n * y])
                    break;
            }

            // Right
            int right = 0;
            for (int i = x+1; i < n; i++)
            {
                right++;
                if (h[i + n * y] >= h[x + n * y])
                    break;
            }

            int score = up * down * left * right;
            if (score > best_view)
                best_view = score;
        }
    }

    printf("Best view-score: %d", best_view);

    return 0;
}