#include <vector> 
#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 
 
bool sortByDate(const vector<int>& a, const vector<int>& b) {
    return a[2] < b[2];
}
int main() 
{
    int N, M, I, S; 
    cin >> N >> M >> I >> S;


    vector<vector<int>> interactions(M);
    for (int A, B, D, i = 0; i < M; i++) {
        cin >> A >> B >> D;
        interactions[i] = {A, B, D};
    }
    sort(interactions.begin(), interactions.end(), sortByDate);

    // Array of date of persons sicknessdate : initilized to -1
    int P[N];
    int A, B, D;
    int maxNum = 0;
    int currMax = 0;
    vector<int> start, end;
    for (int p = 0; p < N; p++) {
        P[p] = -1;
    }
    P[0] = 0;
    start.push_back(I);
    end.push_back(I + S);

    for (int i = 0; i < M; i++) {
        A = interactions[i][0], B = interactions[i][1], D = interactions[i][2];
        if (P[A] != -1 && P[B] == -1 && P[A] + I <= D && P[A] + I + S > D) {
            P[B] = D;
            start.push_back(D + I);
            end.push_back(D + I + S);
        }
        if (P[B] != -1 && P[A] == -1 && P[B] + I <= D && P[B] + I + S > D) {
            P[A] = D;
            start.push_back(D + I);
            end.push_back(D + I + S);
        }
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    while (i < start.size() && j < end.size()) {
        if (start[i] < end[j]) {
            currMax++;
            maxNum = max(maxNum, currMax);
            i++;
        }
        else {
            currMax--;
            j++;
        }
    }

    printf("%d", maxNum);

    return 0;
}