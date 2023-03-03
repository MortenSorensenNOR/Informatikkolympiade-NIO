#include <queue>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pPair;

int height(char c)
{
    if (c == 'S')
        return 0;
    else if (c == 'S')
        return 25;
    return c-97;
}

vector<pair<int, int>> neighbours(int i, int j, vector<vector<char>>& grid)
{
    vector<pair<int, int>> n;
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto& move : moves)
    {
        int ii = i + move.first;
        int jj = j + move.second;

        if (0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[0].size())
        {
            if (height(grid[ii][jj]) <= height(grid[i][j]) + 1)
            {
                n.push_back(make_pair(ii, jj));
            }
        }
    }

    return n;
}

vector<pair<int, int>> downNeighbours(int i, int j, vector<vector<char>>& grid)
{
    vector<pair<int, int>> n;
    vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto& move : moves)
    {
        int ii = i + move.first;
        int jj = j + move.second;

        if (0 <= ii && ii < grid.size() && 0 <= jj && jj < grid[0].size())
        {
            if (height(grid[ii][jj]) >= height(grid[i][j]) - 1)
            {
                n.push_back(make_pair(ii, jj));
            }
        }
    }

    return n;
}

bool pPairCompare(const pPair l, const pPair r) 
{ 
    return l.first > r.first;
}

int main()
{
    string line;
    ifstream data_file;
    data_file.open("day12.txt");

    pair<int, int> src, dst;
    vector<vector<char>> grid;
    while(getline(data_file, line))
    {
        vector<char> row;
        for (int i = 0; i < line.size(); i++)
        {
            row.push_back(line[i]);
        }
        grid.push_back(row);
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'S')
                src = make_pair(i, j);
            if (grid[i][j] == 'E')
                dst = make_pair(i, j);
        }
    }

    // ===== Dijkstra's algorithm =====
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    priority_queue<pPair, vector<pPair>, decltype(&pPairCompare)> heap(pPairCompare);

    heap.push(make_pair(0, src));

    while (!heap.empty())
    {
        pPair current = heap.top();
        heap.pop();

        if (!visited[current.second.first][current.second.second])
        {
            visited[current.second.first][current.second.second] = true;
            if (current.second.first == dst.first && current.second.second == dst.second)
            {
                printf("Steps: %d\n", current.first);
                break;
            }
            
            vector<pair<int, int>> nodeNeighbours = neighbours(current.second.first, current.second.second, grid);
            for (auto& neighbour : nodeNeighbours)
            {
                heap.push(make_pair(current.first + 1, neighbour));
            }
        }
    }

    vector<vector<bool>> newVisited(grid.size(), vector<bool>(grid[0].size(), false));
    priority_queue<pPair, vector<pPair>, decltype(&pPairCompare)> newHeap(pPairCompare);

    newHeap.push(make_pair(0, dst));

    while (!newHeap.empty())
    {
        pPair current = newHeap.top();
        newHeap.pop();

        if (!newVisited[current.second.first][current.second.second])
        {
            newVisited[current.second.first][current.second.second] = true;
            if (grid[current.second.first][current.second.second] == 'a')
            {
                printf("Steps: %d\n", current.first);
                break;
            }
            
            vector<pair<int, int>> nodeNeighbours = downNeighbours(current.second.first, current.second.second, grid);
            for (auto& neighbour : nodeNeighbours)
            {
                newHeap.push(make_pair(current.first + 1, neighbour));
            }
        }
    }

    return 0;
}