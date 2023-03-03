#include <vector> 
#include <iostream> 
using namespace std; 

struct Node {
    int index;
    int depth = 0;
    int depthUppwards = 0;
    
    Node* root;
    vector<Node*> children;

    Node(int i, int d) {
        index = i;
        depth = d;
    }

    void connect(vector<vector<int>>& cons, int index) {
        for (int i = 0; i < cons[index].size(); i++) {
            Node* child = new Node(cons[index][i], depth + 1);
            children.push_back(child);
            connect(cons, cons[index][i]);
        }
    }

    void print() {
        print("%d -> %d\n", index, depth);
    }
}

int main() 
{
    int N, M; 
    cin >> N >> M; 

    vector<vector<int>> cons(N);
    for (int A, B, i = 0; i < M; i++) {
        cin >> A >> B;
        cons[A].push_back(B);
        cons[B].push_back(A);
    }
    Node* root = new Node(0, 0);
    root->connect(cons, 0);



    return 0;
}