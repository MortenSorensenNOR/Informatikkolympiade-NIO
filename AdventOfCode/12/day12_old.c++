#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <bits/stdc++.h>
using namespace std;

#define INF 99999999

int idx(int x, int y, int w)
{
    return y * w + x;
}

class Graph
{
public:
    int V;
    map<int, bool> visited;
    list<pair<int, int>>* adj;

    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }
    
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        // adj[v].push_back(make_pair(u, w));
    }

    void shortestPath(int src, int dst, int N_x, int N_y)
    {
        vector<int> dist(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;

                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        for (int y = 0; y < N_y; y++)
        {
            for (int x = 0; x < N_x; x++)
            {
                if (idx(x, y, N_x) == src)
                {
                    printf("U");
                }
                else if (dist[idx(x, y, N_x)] != INF)
                {
                    printf("%d", 1);
                }
                else
                {
                    printf("%d", 0);
                }
            }
            printf("\n");
        }

        printf("Solution: %d", dist[dst]);
    }

    void DFS(int src)
    {
        visited[src] = true;
        list<pair<int, int>>::iterator i;
        for (i = adj[src].begin(); i != adj[src].end(); ++i)
        {
            if (!visited[(*i).first])
            {
                DFS((*i).first);
            }
        }
    }
};

int main()
{
    string line;
    ifstream data_file;
    data_file.open("day12.txt");

    int width = 0;
    int src = 0, dst = 0;
    vector<vector<int>> heightMap;
    while(getline(data_file, line))
    {
        vector<int> row;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == 'S')
            {
                src = i + heightMap.size() * width;
                row.push_back(1);
                printf("Found src: %d\n", src);
            }
            else if (line[i] == 'E')
            {
                dst = i + heightMap.size() * width;
                row.push_back(26);
                printf("Found dst: %d\n", dst);
            }
            else
            {
                row.push_back(line[i]-96);
            }
        }
        heightMap.push_back(row);
        width = row.size();
    }

    // int N_x = 8, N_y = 5;
    int N_x = 81, N_y = 41;

    int V = N_x*N_y;
    Graph g(V);
  
    for (int y = 0; y < N_y; y++)
    {
        for (int x = 0; x < N_x; x++)
        {
            if (y > 0 && abs(heightMap[y-1][x] - heightMap[y][x]) <= 1)
            {
                g.addEdge(idx(x, y, N_x), idx(x, y-1, N_x), 1);
            }
            if (y < N_y-1 && abs(heightMap[y+1][x] - heightMap[y][x]) <= 1)
            {
                g.addEdge(idx(x, y, N_x), idx(x, y+1, N_x), 1);
            }
            if (x > 0 && abs(heightMap[y][x-1] - heightMap[y][x]) <= 1)
            {
                g.addEdge(idx(x, y, N_x), idx(x-1, y, N_x), 1);
            }
            if (x < N_x-1 && abs(heightMap[y][x+1] - heightMap[y][x]) <= 1)
            {
                g.addEdge(idx(x, y, N_x), idx(x+1, y, N_x), 1);
            }
        }
    }

    g.DFS(src);
    if (g.visited[dst - 7 * N_x])
    {
        printf("Found path...");
    }

    // printf("Src: %d    Dst: %d\n", src, dst);
    // g.shortestPath(dst, src, N_x, N_y);
  
    return 0;
}