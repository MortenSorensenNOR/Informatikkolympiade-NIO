#include <vector> 
#include <iostream> 
using namespace std; 

struct Concert
{
    int x, y;
    int b;

    Concert(int xPos, int yPos, int price)
    {
        x = xPos;
        y = yPos;
        b = price;
    }

    int price(Concert c)
    {
        return abs(x-c.x) + abs(y-c.y) + c.b;
    }
};

vector<Concert> input(int& N, int& T)
{
    cin >> N;
    cin >> T;
    vector<Concert> concerts;
    concerts.push_back(Concert(0, 0, 0));
    for (int i = 0; i < N; i++)
    {
        int x, y, b;
        cin >> x;
        cin >> y;
        cin >> b;
        Concert c(x, y, b);
        concerts.push_back(c);
    }

    return concerts;
}

int main() 
{
    int N, T; 
    vector<Concert> concerts = input(N, T);

    vector<vector<pair<int, int>>> cost(N + 1);
    cost[N] = {{concerts[N].price(concerts[N]), 0}};
    cost[N-1] = {{concerts[N-1].price(concerts[N]), 1}};
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N + 1; j++) {
            for (int k = 0; k < cost[j].size(); k++) {
                if (cost[j][k].first + concerts[i].price(concerts[j]) < T) {
                    cost[i].push_back({ cost[j][k].first + concerts[i].price(concerts[j]), cost[j][k].second + 1 });
                }
            }
        }
        if (concerts[i].price(concerts[N]) < T) {
            cost[i].push_back({ concerts[i].price(concerts[N]), 1});
        }
    }

    int maxNum = 0;
    for (int i = 0; i < cost[0].size(); i++) {
        if (cost[0][i].second > maxNum) {
            maxNum = cost[0][i].second;
        }
    }
    printf("%d", maxNum);

    return 0;
}


/*

0 - 1 - 2 - 3 - 4 - 5 - 6

cost[5] = { price(from 5 to 6) };
cost[4] = { price(from 4 to 6), price(from 4 to 5) + cost[5] };
cost[3] = { price(from 3 to 6), price(from 3 to 4) + cost[4], price(from 3 to 5) + cost[5] };
cost[2] = { price(from 2 to 6), price(from 2 to 3) + cost[3], price(from 2 to 4) + cost[4], price(from 2 to 5) + cost[5] };
cost[1] = { price(from 1 to 6), price(from 1 to 2) + cost[2], price(from 1 to 3) + cost[3], price(from 1 to 4) + cost[4], price(from 1 to 5) + cost[5] };
cost[0] = { price(from 0 to 6), price(from 0 to 1) + cost[1], price(from 0 to 2) + cost[2], price(from 0 to 3) + cost[3], price(from 0 to 4) + cost[4], price(from 0 to 5) + cost[5] };

vector<vector<int>> cost(N, vector<int>());
cost[N - 2] = {price(N-2, N-1)};
for (int i = N - 3; i; i--) {
    cost[i] = {};
    for (int j = i + 1; j < N; j++) {
        vector<int> c = {};
        for (int k = 0; k < cost[j].size(); k++) {
            c.push_back(cost[j][k] + price(i, j));
        }
        cost[i].push_back(c);
    }
    cost[i].push_back({price(i, N - 1)});
}
//                price/dist
vector<vector<pair<int, int>>> cost(N, vector<pair<int, int>>());
cost[N - 2] = {{price(N-2, N-1)}};
for (int i = N - 3; i; i--) {
    for (int j = i + 1; j < N; j++) {
        vector<pair<int, int>> = {};
        for (int k = 0; K < cost[j].size(); k++) {
            c.push_back({ cost[j][k].first + price(i, j), cost[j][k].second + 1});
        }
        cost[i].push_back(c);
    }
    cost[i].push_back({{price(i, N - 1), 1}});
}

int maxNumOfConcerts = 0;
const int money = MAX_INT;
for (int i = 0; i < cost[0].size(); i++) {
    if (cost[0][i].first < money) {
        if (cost[0][i].second > maxNumOfConcerts) {
            maxNumOfConcerts = cost[0][i].second;
        }
    }
}

printf("%d", maxNumOfConcerts);

*/







