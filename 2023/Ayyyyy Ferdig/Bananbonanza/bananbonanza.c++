#include <vector> 
#include <iostream> 
using namespace std; 

/*
valg = 0: Bergen, dvs. i + 3
valg = 1: Oslo, dvs. i + 2
*/

vector<vector<long long>> dp;
long long dfs(int i, int valg, vector<pair<int, int>>& priser) {
    if (i >= priser.size()) return 0;
    if (dp[i][valg] >= 0) return dp[i][valg];

    long long vente = dfs(i + 1, valg, priser);
    if (valg == 1) {
        long long bergen = dfs(i + 3, 0, priser) + priser[i].first; 
        dp[i][valg] = max(bergen, vente);
    } else if (valg == 2) {
        long long oslo = dfs(i + 2, 0, priser) + priser[i].second;
        dp[i][valg] = max(oslo, vente);
    } else {
        long long oslo = dfs(i + 2, 2, priser);
        long long bergen = dfs(i + 3, 1, priser);
        dp[i][valg] = max(bergen, oslo);
    }

    return dp[i][valg];
}

int main() 
{
    int N; 
    cin >> N; 
    dp.resize(N, vector<long long>(3, -1));

    vector<pair<int, int>> priser(N);
    for (int b, o, i = 0; i < N; i++) {
        cin >> b >> o;
        priser[i] = {b, o};
    }

    long long ans = dfs(0, 0, priser);
    cout << ans;

    return 0;
}