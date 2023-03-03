#include <math.h> 
#include <vector> 
#include <iostream> 
using namespace std; 

#define INF 9999999
#define State pair<uint32_t, uint32_t>

int N, M; 
string S;
vector<uint64_t> kompatibel;
bool canBeRoot(uint32_t& set, int element) {
    for (int i = 0; i < 26; i++) {
        if (set & (1UL << i)) {
            if (kompatibel[i] & (1UL << element)) continue;
            else return false;
        }
    }
    return true;
}

bool canBeElement(uint32_t& roots, int element) {
    if (roots & kompatibel[element]) return true;
    return false;
}

void addToRoots(State& state, int element) {
    // Legger til elementet i settet
    state.first |= (1UL << element);
    // Legger til elementet i root
    state.second |= (1UL << element);
    // Fjerner alle elementer fra settet 
    // som ikke er kompatibel med element
    state.second &= kompatibel[element];
}

void addToElements(State& state, int element) {
    // Legger til elementet i settet
    state.first |= (1UL << element);
    // Fjerner alle elementer fra settet 
    // som ikke er kompatibel med element
    state.second &= kompatibel[element];
}

int main() 
{
    cin >> N >> M;
    cin >> S;
    kompatibel.resize(26, (1 << 26) - 1);

    char O, U;
    for (int i = 0; i < M; i++) {
        cin >> O >> U;
        kompatibel[U - 'A'] &= (~(1 << (O - 'A')));
    } 

    State state = {0, 0};
    int index = 0;
    int element = -1;
    int minAvdelinger = 0;
    while (index < S.size()) {
        element = S[index] - 'A';
        if (canBeRoot(state.first, element)) {
            addToRoots(state, element);
        } else if (canBeElement(state.second, element)) {
            addToElements(state, element);
        } else {
            minAvdelinger++;
            state = {1UL << element, 1UL << element};
        }
        index++;
    }

    printf("%d", minAvdelinger + 1);

    return 0;
}