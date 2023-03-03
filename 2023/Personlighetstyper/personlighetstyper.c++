#include <math.h> 
#include <vector> 
#include <iostream> 
using namespace std; 

#define INF 9999999
#define State pair<uint32_t, uint32_t>

int N, M; 
string S;
vector<vector<int>> dp;
vector<uint64_t> kompatibel;
int muligheter(State state, int element) {
    int mulig = 0;
    if (state.second & kompatibel[element]) mulig += 1;
    for (int i = 0; i < 26; i++) {
        if (state.first & (1UL << i)) {
            if (kompatibel[i] & (1UL << element)) continue;
            else return mulig;
        }
    }
    return mulig + 2;
}

State getNewState(State oldState, int element, int type) {
    State newState = {oldState.first, oldState.second};
    if (type == 1) {
        // Legger til elementet i settet
        newState.first |= (1UL << element);
        // Fjerner alle elementer fra settet 
        // som ikke er kompatibel med element
        newState.second &= kompatibel[element];
    } else if (type == 2) {
        // Legger til elementet i settet
        newState.first |= (1UL << element);
        // Legger til elementet i root
        newState.second |= (1UL << element);
        // Fjerner alle elementer fra settet 
        // som ikke er kompatibel med element
        newState.second &= kompatibel[element];
    }
    return newState;
}

int dfs(State state, int start, int index) {
    if (index >= S.size()) return 1;
    if (dp[start][index] != INF) return dp[start][index];

    int valg = muligheter(state, S[index] - 'A');
    int includeAsElement = INF, includeAsRoot = INF;
    State notIncludeState = getNewState({0, 0}, S[index] - 'A', 2);
    int notInclude = dfs(notIncludeState, index, index + 1) + 1;
    if (valg == 1 || valg == 3) {
        State includeElementState = getNewState(state, S[index] - 'A', 1);
        includeAsElement = dfs(includeElementState, start, index + 1);
    }
    if (valg == 2 || valg == 3) {
        State includeRootState = getNewState(state, S[index] - 'A', 2);
        includeAsElement = dfs(includeRootState, start, index + 1);
    }
    return dp[start][index] = min(min(includeAsElement, includeAsRoot), notInclude);
}

int main() 
{
    cin >> N >> M;
    cin >> S;
    dp.resize(N, vector<int>(N, INF));
    kompatibel.resize(26, (1 << 26) - 1);

    char O, U;
    for (int i = 0; i < M; i++) {
        cin >> O >> U;
        kompatibel[U - 'A'] &= (~(1 << (O - 'A')));
    } 

    State startState = getNewState({0, 0}, S[0] - 'A', 2);
    int minAvdelinger = dfs(startState, 0, 1);
    printf("%d", minAvdelinger);

    return 0;
}