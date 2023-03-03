#include <vector> 
#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

void input(int& N, int& K, vector<pair<int, int>>& rabatter) 
{
    cin>>N; 
    cin>>K; 
    for (int i = 0; i < K; i++)
    {
        int r, m;
        cin >> r;
        cin >> m;
        rabatter.push_back(make_pair(r, m));
    }
}

bool sortPair(const pair<int, int>& a, const pair<int, int>& b)
{
    return (a.second > b.second);
}

int main() 
{
    int N, K; 
    vector<pair<int, int>> rabatter;
    input(N, K, rabatter); 

    int greatestDiscount = 0;
    sort(rabatter.begin(), rabatter.end(), sortPair);

    for (int i = 0; i < K; i++)
    {
        if (N > rabatter[i].second)
        {
            vector<bool> possible(N - rabatter[i].second + 1, false);
            possible[0] = true;

            for (int j = i; j < K; j++)
            {
                for (int n = N - rabatter[i].second; n >= 0; n--)
                {
                    if (possible[n] && n + rabatter[j].first <= N - rabatter[i].second)
                    {
                        possible[n + rabatter[j].first] = true;
                    }
                }
            }

            for (int n = N - rabatter[i].second; n >= 0; n--)
            {
                if (possible[n])
                {
                    if (n > greatestDiscount)
                    {
                        greatestDiscount = n;
                    }
                    break;
                }
            }
        }
    }

    printf("%d", N - greatestDiscount);

    return 0;
}