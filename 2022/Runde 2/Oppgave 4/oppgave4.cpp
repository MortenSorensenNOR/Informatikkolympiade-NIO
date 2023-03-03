#include <vector> 
#include <numeric>
#include <iostream> 
#include <algorithm> 
using namespace std; 

int fortjeneste(int interval_start, int pos, vector<vector<int>>& baner, int Max) {
    int tjenste = 0;
    if (abs(interval_start - pos) > Max) {
        return 0;
    } else if (interval_start > pos) {
        for (int i = pos; i <= interval_start; i++) {
            for (int j = pos; j <= interval_start; j++) {
                tjenste += baner[i][j];
            }
        }
    } else if (interval_start < pos) {
        for (int i = interval_start; i <= pos; i++) {
            for (int j = interval_start; j <= pos; j++) {
                tjenste += baner[i][j];
            }
        }
    } 

    return tjenste;
}

int main() 
{
    int N, T, K; 
    cin >> N;
    cin >> T;
    cin >> K;
    vector<vector<int>> baner(N, vector<int>(N));
    vector<vector<vector<int>>> prof(N, vector<vector<int>>(N, vector<int>(T + 1, 0)));

    int a, b, p;
    for (int i = 0; i < K; i++) {
        cin >> a;
        cin >> b;
        cin >> p;
        baner[a][b] = p;
    }

    for (int pos = N - 2; pos >= 0; pos--) {
        for (int interval_start = 0; interval_start < N; interval_start++) {
            for (int t = 1; t <= T; t++) {
                printf("(%d, %d) -> %d : %d\n", interval_start, pos, prof[pos+1][pos+1][t], prof[pos+1][interval_start][t-1] + fortjeneste(interval_start, pos+1, baner, T));
                prof[pos][interval_start][t] = max(prof[pos+1][pos+1][t], prof[pos+1][interval_start][t-1] + fortjeneste(interval_start, pos+1, baner, T));
            }
        }
    }

    printf("%d", prof[0][0][T]);

    return 0;
}