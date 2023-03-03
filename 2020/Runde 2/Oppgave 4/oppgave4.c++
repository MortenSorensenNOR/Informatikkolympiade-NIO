#include <queue> 
#include <vector>
#include <iostream> 
using namespace std; 

int main() 
{
    int N; 
    cin >> N;

    int num = 0, sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x, i = 0; i < N; i++) {
        cin >> x;
        sum += x;
        pq.push(x);
        if (sum < 0) {
            sum -= pq.top();
            pq.pop();
            num++;
        }
    }

    printf("%d", num);

    return 0;
}