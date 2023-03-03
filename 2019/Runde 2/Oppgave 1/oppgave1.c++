#include <vector> 
#include <iostream> 
using namespace std; 

int main() 
{
    int N; 
    cin >> N;

    long long tid = 15;
    int prevA, prevB;
    cin >> prevA >> prevB;
    for (int A, B, i = 1; i < N; i++) {
        cin >> A >> B;
        tid += 15 + abs(A - prevA) + abs(B - prevB);
        prevA = A; prevB = B;
    }
    printf("%d", tid);

    return 0;
}