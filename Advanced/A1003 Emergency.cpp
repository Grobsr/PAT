#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_V = 510;//最大顶点数
const int INF = 0x3fffffff;//无穷大

int numOfV, numOfE, start, finish, graph[MAX_V][MAX_V], teams[MAX_V];
int shortest[MAX_V], allTeams[MAX_V], numOfShortest[MAX_V];
bool visited[MAX_V] = {false};

void Dijkstra(int start) {
    fill(shortest, shortest + MAX_V, INF);
    memset(allTeams, 0, sizeof(allTeams));
    memset(numOfShortest, 0, sizeof(numOfShortest));
    shortest[start] = 0;
    allTeams[start] = teams[start];
    numOfShortest[start] = 1;
    int current, min;
    //找到当前剩余的顶点中，与起点start距离最短的那个下标记为currnt
    for (int i = 0; i < numOfV; ++i) {
        current = -1, min = INF;
        for (int v = 0; v < numOfV; ++v) {
            if (!visited[v] && shortest[v] < min) {
                current = v;
                min = shortest[v];//更新最小距离
            }
        }
        //如果没有符合条件的顶点则函数结束
        if (current == -1) {
            return;
        }
        visited[current] = true;
        for (int v = 0; v < numOfV; ++v) {
            if (!visited[v] && graph[current][v] != INF) {
                if (shortest[current] + graph[current][v] < shortest[v]) {
                    shortest[v] = shortest[current] + graph[current][v];//更新最短路径
                    allTeams[v] = allTeams[current] + teams[v];//更新可召集的队伍数
                    numOfShortest[v] = numOfShortest[current];//继承最短路径数
                } else if (shortest[current] + graph[current][v] == shortest[v]) {
                    numOfShortest[v] += numOfShortest[current];//增加最短路径数
                    if (allTeams[current] + teams[v] > allTeams[v]) {
                        allTeams[v] = allTeams[current] + teams[v];//更新能够召集队伍数
                    }
                }
            }
        }
    }
}

int main() {
    //读入顶点数、边数、起点、终点
    cin >> numOfV >> numOfE >> start >> finish;
    for (int i = 0; i < numOfV; ++i) {
        cin >> teams[i];
    }
    fill(graph[0], graph[0] + MAX_V * MAX_V, INF);//起始时图中任意两顶点之间不可达
    int from, to;
    //读入图的信息
    for (int i = 0; i < numOfE; ++i) {
        cin >> from >> to;
        cin >> graph[from][to];
        graph[to][from] = graph[from][to];
    }
    Dijkstra(start);//调用Dijkstra()函数
    cout << numOfShortest[finish] << " " << allTeams[finish];
    return 0;
}
