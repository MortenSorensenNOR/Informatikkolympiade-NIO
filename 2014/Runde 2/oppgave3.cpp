#include <iostream> 
#include <vector> 
#include <bits/stdc++.h>
#include <chrono>

int search_closest(const std::vector<int>& sorted_array, int x) {

    auto iter_geq = std::lower_bound(sorted_array.begin(), sorted_array.end(), x);

    if (iter_geq == sorted_array.begin()) {
        return 1;
    }

    int a = *(iter_geq - 1);
    int b = *(iter_geq);

    if (abs(x - a) < abs(x - b)) {
        if (x == a) {
            return iter_geq - sorted_array.begin();
        }
        return iter_geq - sorted_array.begin() - 1;
    } else {
        if (x == b) {
            return iter_geq - sorted_array.begin() - 1;
        }
        return iter_geq - sorted_array.begin();
    }
}

int main() 
{
    // Input 
    int N; 
    int T; 
    std::cin >> N; 
    std::cin >> T;

    std::vector<int> p = {};
    for (int i = 0; i < N; i++) {
        int c;
        std::cin >> c;
        p.push_back(c);
    }

    std::vector<int> a = {};
    for (int i = 0; i < T; i++) {
        int c;
        std::cin >> c;
        a.push_back(c);
    }
    // Program  
    std::sort(p.begin(), p.end());
    for (int j = 0; j < a.size(); j++) {
        int i = search_closest(p, a[j]);
        std::cout << std::abs(p[i] - a[j]) << std::endl;
    }

    return 0;
}