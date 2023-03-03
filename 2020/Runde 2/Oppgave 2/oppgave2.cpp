#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main() 
{
    int N; 
    std::cin >> N;

    int a, b, c;
    vector<vector<int>> con(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        con[i].push_back(a-1);
        con[i].push_back(b-1);
        con[i].push_back(c-1);
        con[i].push_back(i+1);
    }

    queue<pair<int, int>> q;
    vector<int> solution(N + 1, N+2);
    q.push({0, 1});
    solution[0] = 1;
    while (!q.empty()) {
        auto [idx, dist]  = q.front();
        q.pop();
        for (auto& w : con[idx]) {
            if (dist+1 < solution[w]) {
                solution[w] = dist+1;
                q.push({w, dist+1});
            }   
        }
    }

    printf("%d", solution[N-1]);

    return 0;
}