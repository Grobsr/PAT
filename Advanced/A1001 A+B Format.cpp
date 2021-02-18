#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    stack<int> result;
    int a, b, sum = 0, length;
    cin >> a >> b;
    sum = a + b;
    //负数一律取成正的来处理
    if (sum < 0) {
        cout << "-";
        sum = -sum;
    }
    //单独处理和为0的情况
    if (!sum){
        cout << 0;
    }
    //计算结果的每一位数字并存在栈中
    while (sum) {
        result.push(sum % 10);
        sum /= 10;
    }
    length = result.size(); //保存栈初始的元素个数（随着弹出元素这个数量会减少）
    while (!result.empty()) {
        if (result.size() != length && result.size() % 3 == 0) { //栈中的元素个数为3的倍数且不在末尾则输出一个逗号
            cout << ",";
        }
        cout << result.top();// 输出各位数字
        result.pop();
    }
}
