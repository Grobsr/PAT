#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    double odds[10] = {0.0};
    for (int i = 0; i < 3; ++i) {
        cin >> odds[0] >> odds[1] >> odds[2];
        double *max = max_element(odds, odds + 3);//找出最大的赔率
        //根据最大赔率的下标位置分别输出字母
        switch (max - &odds[0]) {
            case 0:
                cout << "W ";
                break;
            case 1:
                cout << "T ";
                break;
            case 2:
                cout << "L ";
                break;
        }
        //把最大的赔率存到数组的空闲位置
        odds[i + 3] = *max;
    }
    double maxProfit = odds[3] * odds[4] * odds[5] * 0.65 - 1;
    printf("%.2lf", maxProfit * 2);
}
