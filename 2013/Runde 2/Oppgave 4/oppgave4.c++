#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> input(int& N)
{
    cin >> N;
    vector<vector<int>> v(N, vector<int>());
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            int f;
            cin >> f;
            v[i].push_back(f);
        }
    }

    return v;
}

int graphColor(vector<vector<int>>& v, int src, vector<int>& colors)
{
    int val1 = 1, val2 = 0;
    colors[src] = 1;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < v[u].size(); i++)
        {
            if (colors[v[u][i]] == -1)
            {
                colors[v[u][i]] = 1 - colors[u];
                if (colors[v[u][i]] == 1) 
                {
                    val1++;
                }
                else
                {
                    val2++;
                }
                q.push(v[u][i]);
            }
            else if (colors[v[u][i]] == colors[u])
            {
                printf("0");
                return 0;
            }
        }
    }

    return max(val1, val2);
}

void graphColor(vector<vector<int>>& v, vector<int>& colors, int& maxNum)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (colors[i] == -1)
        {
            int n = graphColor(v, i, colors);
            if (n == 0)
            {
                return;
            }
            maxNum += n;
        }
    }
}

int main()
{
    int N;
    vector<vector<int>> v = input(N);
    vector<int> colors(N, -1);

    // Graph Coloring with two colors: scarf & book
    int maxNum = 0;
    graphColor(v, colors, maxNum);
    if (maxNum) printf("%d", maxNum);

    return 0;
}