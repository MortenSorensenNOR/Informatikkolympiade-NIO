#include <queue> 
#include <vector> 
#include <iostream> 
using namespace std; 

int graphColor(vector<vector<int>>& adj, int src, vector<int>& colors) {
    int val1 = 1, val2 = 0, setValues = 0;
    colors[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (colors[u] == 2) continue;
        for (int i = 0; i < adj[u].size(); i++) {
            if (colors[adj[u][i]] == -1) {
                colors[adj[u][i]] = 1 - colors[u];
                if (colors[adj[u][i]] == 1) {
                    val1++;
                } else {
                    val2++;
                }
                q.push(adj[u][i]);
            } else if (colors[adj[u][i]] == colors[u]) {
                if (colors[u] == 1) val1--;
                else val2--;
                colors[adj[u][i]] = 2;
                setValues++;
            }
        }
    }

    // printf("1: %d, 2: %d, set: %d\n", val1, val2, setValues);

    return min(val1, val2) + setValues;
}

void graphColor(vector<vector<int>>& adj, vector<int>& colors, int& minNum) {
    for (int i = 0; i < adj.size(); i++) {
        if (colors[i] == -1) {
            int n = graphColor(adj, i, colors);
            minNum += n;
        }
    }
}

int main() 
{
    int N, M, K, P; 
    cin >> N >> M >> K >> P; 

    vector<int> colors(N, -1);
    vector<vector<int>> adj(N);

    int minNum = 0;
    for (int u, v, i = 0; i < M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int U, V, i = 0; i < P; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    graphColor(adj, colors, minNum);
    printf("%d", minNum);

    // for (int i = 0; i < adj.size(); i++) {
    //     printf("%d: ", i);
    //     for (int j = 0; j < adj[i].size(); j++) {
    //         printf("%d ", adj[i][j]);
    //     }
    //     printf("\n");
    // }


    return 0;
}