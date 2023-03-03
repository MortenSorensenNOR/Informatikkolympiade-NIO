#include <set> 
#include <map> 
#include <vector> 
#include <iostream> 
using namespace std; 

int traverse(map<string, vector<string>>& m, string& src, set<string>& researched) {
    if (m[src].size() == 0) return 0;
    int dependencies = 0;
    for (int i = 0; i < m[src].size(); i++) {
        if (researched.find(m[src][i]) == researched.end()) {
            dependencies += traverse(m, m[src][i], researched) + 1;
            researched.insert(m[src][i]);
        }
    }
    return dependencies;
}
 
int main() 
{
    int N; 
    cin >> N;

    int A;
    string tech; 
    map<string, vector<string>> m;
    for (int i = 0; i < N; i++) {
        cin >> tech >> A;
        vector<string> techs(A);
        for (int j = 0; j < A; j++) {
            cin >> techs[j];
        }
        m[tech] = techs;
    }

    string src = "datamaskiner";
    set<string> researched;
    int num = traverse(m, src, researched) + 1;
    printf("%d", num);

    return 0;
}