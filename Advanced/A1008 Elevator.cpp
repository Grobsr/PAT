#include <iostream>

using namespace std;

int main() {
    int num, res = 0, previous = 0, current;
    cin >> num;
    //读入停靠的层数，并分别累计所需时间
    for (int i = 0; i < num; ++i) {
        cin >> current;
        if (current > previous) {
            res += (current - previous) * 6;
        } else{
            res += (previous - current) * 4;
        }
        res += 5;//不论上升还是下降总要停靠5秒
        previous = current;
    }
    cout << res;
}
