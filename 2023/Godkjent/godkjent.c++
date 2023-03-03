#include <vector> 
#include <iostream> 
using namespace std; 

struct Node {
    int size = 1;
    int root = 0;
    int index = 0;
    int levelIndex = 0;
    int postIndex = 0;
    vector<int> children; 
};

int treeSetup(vector<Node>& ansatte, vector<int>& postOrder, vector<int>& levelOrder, int root) {
    ansatte[root].levelIndex = levelOrder.size();
    levelOrder.push_back(root);
    if (ansatte[root].children.size() == 0)  {
        ansatte[root].postIndex = postOrder.size();
        postOrder.push_back(root);
        return 1;
    }
    for (int i = 0; i < ansatte[root].children.size(); i++) {
        ansatte[root].size += treeSetup(ansatte, postOrder, levelOrder, ansatte[root].children[i]);
    }
    ansatte[root].postIndex = postOrder.size();
    postOrder.push_back(root);
    return ansatte[root].size;
}

void leggTilArbeid(vector<Node>& ansatte, vector<int>& postOrder, vector<int>& arbeid, int src, int& work) {
    int root = ansatte[src].root;
    if (ansatte[root].size < work) {
        leggTilArbeid(ansatte, postOrder, arbeid, root, work);
    } 
    else {
        for (int i = ansatte[src].postIndex - ansatte[src].size + 1; i <= ansatte[src].postIndex; i++) {
            arbeid[postOrder[i]]++;
        }
        work -= ansatte[src].size;
        int index = ansatte[root].postIndex - ansatte[root].size + 1;
        while (work) {
            if (index == ansatte[src].postIndex - ansatte[src].size + 1) {
                index += ansatte[src].size;
            }
            arbeid[postOrder[index]]++;
            work--;
            index++;
        }
    }
}

int main() 
{
    int N, M; 
    cin >> N >> M; 

    vector<int> postOrder;
    vector<int> levelOrder;
    vector<Node> ansatte(N);
    vector<int> arbeid(N, 0);
    for (int L, i = 1; i < N; i++) {
        cin >> L;
        ansatte[i].index = i;
        ansatte[i].root = L;
        ansatte[L].children.push_back(i);
    }
    treeSetup(ansatte, postOrder, levelOrder, 0);

    for (int W, G, i = 0; i < M; i++) {
        cin >> W >> G;
        if (G == 1) arbeid[W]++;
        else {
            leggTilArbeid(ansatte, postOrder, arbeid, W, G);
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", arbeid[i]);
    }

    return 0;
}