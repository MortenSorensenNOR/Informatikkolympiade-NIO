#include <math.h> 
#include <vector> 
#include <iostream> 
#include <algorithm> 
using namespace std; 

int main() 
{
    int N, K, Y; 
    cin >> N >> K >> Y;
    vector<int> votes(K - 1);
    for (int V, i = 0; i < K - 1; i++) {
        cin >> votes[i];
    } 
    sort(votes.begin(), votes.end());

    int ans = Y, numOfTopVotes = 1;
    while (votes.back() > ans) {
        if (votes.back() == votes[K - numOfTopVotes - 2]) {
            numOfTopVotes++;
        }
        if (numOfTopVotes == votes.size()) {
            int diff = (votes.back() - ans)/(numOfTopVotes + 1);
            ans += diff * numOfTopVotes;
            votes.back() -= diff;
            ans += votes.back() - ans;
            votes.back()--;
        }
        else if (ans + (votes.back() - votes[K - numOfTopVotes - 2]) * numOfTopVotes > votes[K - numOfTopVotes - 2]) {
            int diff = (votes.back() - ans)/(numOfTopVotes + 1);
            ans += diff * numOfTopVotes;
            votes.back() -= diff;
            ans += votes.back() - ans;
            votes.back()--;
        }
        else {
            int diff = (votes.back() - votes[K - numOfTopVotes - 2]);
            ans += diff * numOfTopVotes;
            votes.back() -= diff;
            numOfTopVotes++;
        }
    }

    printf("%d", ans - Y);

    return 0;
}