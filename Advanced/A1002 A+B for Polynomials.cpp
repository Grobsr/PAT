#include <iostream>
#include <stack>
 
using namespace std;
 
int main(){
    const int maxNum = 1010;
    double result[maxNum] = {0.0};
    int numOfA, numOfB, exponent;
    double coefficient;
    cin >> numOfA;
    //读入多项式A各项的指数和系数
    for (int i = 0; i < numOfA; ++i) {
        cin >> exponent >> coefficient;
        result[exponent] += coefficient;//把每一项的系数加到结果多项式中
    }
    cin >> numOfB;
    //读入多项式A各项的指数和系数
    for (int i = 0; i < numOfB; ++i) {
        cin >> exponent >> coefficient;
        result[exponent] += coefficient;//把每一项的系数加到结果多项式中
    }
    stack<int> out;
    //遍历结果多项式，让系数不为零的项下标（指数）入栈
    for (int i = 0; i < maxNum; ++i) {
        if (result[i] != 0.0){
            out.push(i);
        }
    }
    cout << out.size();//输出多项式的项数
    while (!out.empty()){
        printf(" %d %.1f", out.top(), result[out.top()]);//输出指数和系数
        out.pop();
    }
}
