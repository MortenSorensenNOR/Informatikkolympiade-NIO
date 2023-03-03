#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int N;
    string code;
    string decoded;

    cin >> N;
    cin >> code;

    for (int i = 0; i < code.length(); i++) 
    {
        decoded.push_back(char(64 + (int(code[i]) - 64 + N) % 26));
    }
    
    cout << decoded;

    return 0;
}