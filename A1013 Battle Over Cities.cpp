/*
 * DFS实现
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = 1010;//最大顶点数

int numOfCities;
int graph[MAX_V][MAX_V] = {0};
bool enqueued[MAX_V] = {false};

void BFS(int city) {
    queue<int> q;
    q.push(city);
    int front;
    enqueued[city] = true;//起点城市（顶点）标记成已入队
    while (!q.empty()){
        front = q.front();
        q.pop();
        for (int i = 1; i <= numOfCities; ++i) {
            if (!enqueued[i] && graph[front][i] == 1) {
                q.push(i);
                enqueued[i] = true;//当前城市（顶点）标记成已入队
            }
        }
    }
}

int main() {
    int numOfHighways, numOfCitiesConcerned, from, to;
    cin >> numOfCities >> numOfHighways >> numOfCitiesConcerned;
    //读入边的信息
    for (int i = 0; i < numOfHighways; ++i) {
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    int current, res;
    //读入需要计算的顶点编号并用BFS处理
    for (int i = 0; i < numOfCitiesConcerned; ++i) {
        fill(enqueued, enqueued + MAX_V, false);
        cin >> current;
        enqueued[current] = true;//标记为已访问，从图中去掉这个顶点
        res = 0;
        for (int j = 1; j <= numOfCities; ++j) {
            if (!enqueued[j]) {
                BFS(j);
                res++;
            }
        }
        cout << res - 1 << endl;
    }
}





/*
 * BFS实现
 */
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX_V = 1010;//最大顶点数

int numOfCities;
int graph[MAX_V][MAX_V] = {0};
bool enqueued[MAX_V] = {false};

void BFS(int city) {
    queue<int> q;
    q.push(city);
    int front;
    enqueued[city] = true;//起点城市（顶点）标记成已入队
    while (!q.empty()){
        front = q.front();
        q.pop();
        for (int i = 1; i <= numOfCities; ++i) {
            if (!enqueued[i] && graph[front][i] == 1) {
                q.push(i);
                enqueued[i] = true;//当前城市（顶点）标记成已入队
            }
        }
    }
}

int main() {
    int numOfHighways, numOfCitiesConcerned, from, to;
    cin >> numOfCities >> numOfHighways >> numOfCitiesConcerned;
    //读入边的信息
    for (int i = 0; i < numOfHighways; ++i) {
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    int current, res;
    //读入需要计算的顶点编号并用BFS处理
    for (int i = 0; i < numOfCitiesConcerned; ++i) {
        fill(enqueued, enqueued + MAX_V, false);
        cin >> current;
        enqueued[current] = true;//标记为已入队，从图中去掉这个顶点
        res = 0;
        for (int j = 1; j <= numOfCities; ++j) {
            if (!enqueued[j]) {
                BFS(j);
                res++;
            }
        }
        cout << res - 1 << endl;
    }
}





/*
 * 并查集实现
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 1010;//最大顶点数

vector<int> graph[MAX_V];
bool visited[MAX_V] = {false};//根结点的访问标记
int father[MAX_V];

//初始化father[MAX_V]数组和visited[MAX_V]数组
void init() {
    for (int i = 0; i < MAX_V; ++i) {
        father[i] = i;
        visited[i] = false;
    }
}

//找根结点和路径压缩
int getRoot(int element) {
    if (element == father[element]) {
        return element;
    } else {
        int recursionRoot = getRoot(father[element]);//递归寻找父结点的根结点
        father[element] = recursionRoot;//设置元素的父结点为根结点
        return recursionRoot;//返回根结点
    }
}
//int getRoot(int nonRecursionRoot){
//    int temp = nonRecursionRoot;//用temp变量暂存元素nonRecursionRoot
//    while (nonRecursionRoot != father[nonRecursionRoot]){
//        nonRecursionRoot = father[nonRecursionRoot];//找到根结点并存在nonRecursionRoot中
//    }
//    while (temp != father[temp]){
//        int copy = temp;//用copy变量暂存元素temp（一开始的nonRecursionRoot）
//        temp = father[temp];//temp回溯父结点（让循环往下走）
//        father[copy] = nonRecursionRoot;//设置元素的父结点为根结点
//    }
//    return nonRecursionRoot;
//}

//并集
void unionSets(int elementA, int elementB) {
    int fatherA = getRoot(elementA);
    int fatherB = getRoot(elementB);
    if (fatherA != fatherB) {
        father[fatherA] = fatherB;
    }
}

int main() {
    int numOfCities, numOfHighways, numOfCitiesConcerned, from, to;
    cin >> numOfCities >> numOfHighways >> numOfCitiesConcerned;
    //读入图的信息，用邻接矩阵存储
    for (int i = 0; i < numOfHighways; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    int current, res, fatherOfI;
    for (int i = 0; i < numOfCitiesConcerned; ++i) {
        cin >> current;
        init();
        //遍历图，并对未被删除且可达的结点对进行并集操作
        for (int j = 1; j <= numOfCities; ++j) {
            for (int k = 0; k < graph[j].size(); ++k) {
                if (j != current && graph[j][k] != current) {
                    unionSets(j, graph[j][k]);
                }
            }
        }
        res = 0;
        for (int j = 1; j <= numOfCities; ++j) {
            if (j != current) {
                fatherOfI = getRoot(j);
                if (!visited[fatherOfI]) {
                    res++;
                    visited[fatherOfI] = true;//标记根结点已被访问
                }
            }
        }
        cout << res - 1 << endl;
    }
}
