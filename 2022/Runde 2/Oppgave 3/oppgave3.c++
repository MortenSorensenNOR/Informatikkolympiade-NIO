#include <cmath>
#include <queue> 
#include <vector> 
#include <float.h> 
#include <iostream> 
#include <algorithm>
using namespace std; 

struct Node {
    int i, j;
    double dist;
    bool cycle;
    bool operator()(Node& a, Node& b) {
        return a.dist > b.dist;
    }
};

int main() 
{
    int N; 
    cin >> N; 

    vector<vector<char>> nodes(N, vector<char>(N));
    vector<vector<int>> height(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> nodes[i][j];
        }
    }

    pair<int, int> dirs[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<pair<double, double>>> minDist(N, vector<pair<double, double>>(N, {DBL_MAX, DBL_MAX}));
    priority_queue<Node, vector<Node>, Node> pq;
    minDist[0][0].first = 0;
    pq.push({0, 0, 0, false});

    int ii, jj;
    while(!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        for (auto& dir : dirs) {
            ii = dir.first + curr.i;
            jj = dir.second + curr.j;

            if (0 <= ii && ii < N && 0 <= jj && jj < N) {
                double walkDist = curr.dist + 50;
                double cycleDist = curr.dist + 10 * pow(2.0, double(height[ii][jj] - height[curr.i][curr.j]) / 100);

                if (walkDist < minDist[ii][jj].first) {
                    if (nodes[curr.i][curr.j] == 'X' && !curr.cycle) {
                        pq.push({ii, jj, walkDist, false});
                        minDist[ii][jj].first = walkDist;
                    } 
                    else if (nodes[curr.i][curr.j] == 'F' && !curr.cycle) {
                        pq.push({ii, jj, walkDist, false});
                        minDist[ii][jj].first = walkDist;
                    }
                    else if (nodes[curr.i][curr.j] == 'T') {
                        pq.push({ii, jj, walkDist, false});
                        minDist[ii][jj].first = walkDist;
                    }
                    else if (nodes[curr.i][curr.j] == '*') {
                        pq.push({ii, jj, walkDist, false});
                        minDist[ii][jj].first = walkDist;
                    }
                }

                if (cycleDist < minDist[ii][jj].second) {
                    if (nodes[curr.i][curr.j] == 'X' && curr.cycle) {
                        pq.push({ii, jj, cycleDist, true});
                        minDist[ii][jj].second = cycleDist;
                    } 
                    if (nodes[curr.i][curr.j] == 'T' && curr.cycle) {
                        pq.push({ii, jj, cycleDist, true});
                        minDist[ii][jj].second = cycleDist;
                    } 
                    else if (nodes[curr.i][curr.j] == 'F') {
                        pq.push({ii, jj, cycleDist, true});
                        minDist[ii][jj].second = cycleDist;
                    }
                    else if (nodes[curr.i][curr.j] == '*') {
                        pq.push({ii, jj, cycleDist, true});
                        minDist[ii][jj].second = cycleDist;
                    }
                }
            }
        }
    }

    if (nodes[N-1][N-1] == '*' || nodes[N-1][N-1] == 'T') {
        printf("%F", min(minDist[N-1][N-1].first, minDist[N-1][N-1].second));
    } else {
        printf("%F", minDist[N-1][N-1].first);
    }

    return 0;
}