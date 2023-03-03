#include <queue> 
#include <vector> 
#include <iostream> 
#include <algorithm>
#include <functional>
using namespace std; 

int main() 
{
    int N, K, G; 
    cin >> N >> K >> G; 

    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int, vector<int>> right;
    for (int X, i = 0; i < N; i++) {
        cin >> X;
        if (X < G) left.push(X);
        else right.push(X);
    }

    long dist = 0;
    while (!left.empty() && !right.empty()) {
        if (G - left.top() < right.top() - G) {
            dist += 2 * (right.top() - G);
            for (int i = 0; i < K; i++) {
                if (right.empty()) break;
                right.pop();
            }
        } else {
            dist += 2 * (G - left.top());
            for (int i = 0; i < K; i++) {
                if (left.empty()) break;
                left.pop();
            }
        }
    }

    if (!left.empty()) {
        while (!left.empty()) {
            dist += 2 * (G - left.top());
            for (int i = 0; i < K; i++) {
                if (left.empty()) break;
                left.pop();
            }
        }
    }
    if (!right.empty()) {
        while (!right.empty()) {
            dist += 2 * (right.top() - G);
            for (int i = 0; i < K; i++) {
                if (right.empty()) break;
                right.pop();
            }
        }
    }

    printf("%d", dist);

    return 0;
}