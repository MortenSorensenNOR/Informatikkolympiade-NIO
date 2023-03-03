#include <queue> 
#include <vector> 
#include <iostream> 
#include <algorithm> 
using namespace std; 


struct sorterLyn {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second; 
        return a.first > b.first;
    }
};

int main() 
{
    int N, K; 
    cin >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, sorterLyn> pq;
    for (int a, b, i = 0; i < K; i++) {
        cin >> a >> b;
        pq.push({a, 0});
        pq.push({b, 1});
    }

    int ans = 0;
    int state = 1;
    for (int i = 0; i < N; i++) {
        while (!pq.empty() && pq.top().first == i && pq.top().second == 0) {
            state = !state;
            pq.pop();
        }
        if (state) ans++;
        while (!pq.empty() && pq.top().first == i && pq.top().second == 1) {
            state = !state;
            pq.pop();
        }
    }
    printf("%d", ans);

    return 0;
}