#include <vector> 
#include <iostream> 
using namespace std; 
 
int main() 
{
    int N, m; 
    cin >> N >> M;
    vector<vector<int>> connections(N);
    for (int a, b, i = 0; i < M; i++) {
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    return 0;
}