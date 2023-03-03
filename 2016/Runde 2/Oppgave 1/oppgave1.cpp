#include <iostream> 
#include <vector> 

int main() 
{
    int N; 
    std::cin >> N; 

    int a;
    std::vector<int> t;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        t.push_back(a%2==0);
    }

    for (int i = 0; i < N; i++) {
        if (t[i]) {
            std::cout << "RIKTIG" << std::endl;
        } else {
            std::cout << "GALT" << std::endl;
        }
    }

    return 0;
}