#include <iostream>

using namespace std;

const int MAX_N = 10010;

int main() {
    int num;
    cin >> num;
    int currentSum = 0, res = -1, currentStart = 0, start = 0, finish = num - 1;
    int sequence[MAX_N];
    for (int i = 0; i < num; ++i) {
        cin >> sequence[i];
        currentSum += sequence[i];//当前和加上序列中待处理的元素
        //当前和为负时直接归零并舍弃子序列
        if (currentSum < 0) {
            currentSum = 0;
            currentStart = i + 1;
        } else if (currentSum > res) {
            res = currentSum;//更新结果
            start = currentStart;//记录起始下标
            finish = i;//记录结束下标
        }
    }
    if (res < 0) {
        res = 0;
    }
    cout << res << " " << sequence[start] << " " << sequence[finish];
}
