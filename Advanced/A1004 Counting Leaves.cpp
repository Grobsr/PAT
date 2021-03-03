/*
 * DFS实现
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


const int MAX_N = 110;//可能出现的最大结点个数

vector<int> tree[MAX_N];//定义树
int leaves[MAX_N] = {0};
int actualHeight = 1;

void DFS(int index, int height){
    actualHeight = max(height, actualHeight);//更新树高
    //如果是叶子结点，叶结点数组相应位置数量自增1
    if (tree[index].empty()){
        leaves[height]++;
        return;
    }
    //对非叶子结点的每个孩子使用DFS进行遍历
    for (auto i : tree[index]) {
        DFS(i, height + 1);
    }
//    for (int i = 0; i < tree[index].size(); i++) {
//        DFS(tree[index][i], height + 1);
//    }
}

int main(){
    int numOfNodes, numOfNon_LeafNodes, current, child, numOfChildren;
    cin >> numOfNodes >> numOfNon_LeafNodes;
    for (int i = 0; i < numOfNon_LeafNodes; ++i) {
        cin >> current >> numOfChildren;
        for (int j = 0; j < numOfChildren; ++j) {
            cin >> child;
            tree[current].push_back(child);
        }
    }
    //从根节点开始遍历，起始高度为1
    DFS(1, 1);
    cout << leaves[1];
    for (int i = 2; i <= actualHeight; ++i) {
        cout <<" " << leaves[i];
    }
    return 0;
}





/*
 * BFS实现
 */
 #include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 110;//可能出现的最大结点个数

vector<int> tree[MAX_N];//定义树
int layer[MAX_N] = {0};//每个结点所在的层数
int leaves[MAX_N] = {0};
int actualHeight = 0;

void BFS(){
    //建立队列取队首
    queue<int> q;
    q.push(1);
    int front;
    while (!q.empty()){
        front = q.front();
        q.pop();
        actualHeight = max(layer[front], actualHeight);//更新树高
        //如果是叶子结点，叶结点数组相应位置数量自增1
        if (tree[front].empty()){
            leaves[layer[front]]++;
        }
        //非叶子结点的每个孩子入队
        for (auto i : tree[front]) {
            layer[i] = layer[front] + 1;
            q.push(i);
        }
//        for (int i = 0; i < tree[front].size(); ++i) {
//            layer[tree[front][i]] = layer[front] + 1;
//            q.push(tree[front][i]);
//        }
    }
}

int main(){
    int numOfNodes, numOfNon_LeafNodes, current, child, numOfChildren;
    cin >> numOfNodes >> numOfNon_LeafNodes;
    for (int i = 0; i < numOfNon_LeafNodes; ++i) {
        cin >> current >> numOfChildren;
        for (int j = 0; j < numOfChildren; ++j) {
            cin >> child;
            tree[current].push_back(child);
        }
    }
    layer[1] = 1;//只含根节点的起始高度为1
    BFS();
    cout << leaves[1];
    for (int i = 2; i <= actualHeight; ++i) {
        cout << " " << leaves[i];
    }
    return 0;
}
