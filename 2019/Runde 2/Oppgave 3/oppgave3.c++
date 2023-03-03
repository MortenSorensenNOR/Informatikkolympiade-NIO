#include <set> 
#include <vector> 
#include <iostream> 
using namespace std; 
 
void traverse(vector<vector<int>>& adj, set<int>& visited, int src) {
    for (int i = 0; i < adj[src].size(); i++) {
        if (visited.find(adj[src][i]) == visited.end()) {
            visited.insert(adj[src][i]);
            traverse(adj, visited, adj[src][i]);
        }
    }
}

int main() 
{
    int N, M; 
    cin >> N >> M;

    set<int> visited;
    vector<bool> result(M);
    vector<vector<int>> adj(N);
    for (int A, B, i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
        visited.clear();
        traverse(adj, visited, 0);
        if (visited.find(1) != visited.end()) {
            result[i] = true;
            adj[A].pop_back();
            adj[B].pop_back();
        }
        else result[i] = false;
    }

    for (int i = 0; i < M; i++) {
        if (result[i]) printf("nei\n");
        else printf("ja\n");
    }

    return 0;
}