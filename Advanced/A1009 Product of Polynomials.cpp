#include <iostream>
#include <stack>

using namespace std;

const int POLY_MAX_N = 1010;//用于计算的多项式最大项数
const int RES_MAX_N = 2020;//结果多项式最大项数

int main() {
    int numOfA, numOfB, exponent;
    double coefficient;
    double A[POLY_MAX_N] = {0.0}, result[RES_MAX_N] = {0.0};
    cin >> numOfA;
    //读入多项式A的指数和系数
    for (int i = 0; i < numOfA; ++i) {
        cin >> exponent >> coefficient;
        A[exponent] = coefficient;
    }
    cin >> numOfB;
    //读入多项式B的指数和系数，同时计算结果多项式
    for (int i = 0; i < numOfB; ++i) {
        cin >> exponent >> coefficient;
        for (int j = 0; j < POLY_MAX_N; ++j) {
            result[j + exponent] += A[j] * coefficient;
        }
    }
    stack<int> out;
    //遍历结果多项式，让系数不为零的项下标（指数）入栈
    for (int i = 0; i < RES_MAX_N; ++i) {
        if (result[i] != 0.0){
            out.push(i);
        }
    }
    cout << out.size();//输出多项式的项数（起始时栈中元素个数）
    while (!out.empty()) {
        printf(" %d %.1f", out.top(), result[out.top()]);//输出指数和系数
        out.pop();
    }
}
