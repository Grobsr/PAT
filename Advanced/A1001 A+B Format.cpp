#include <iostream>
#include <stack>
 
using namespace std;
 
int main() {
    stack<int> result;
    int a, b, sum = 0, length;
    cin >> a >> b;
    sum = a + b;
    if (sum < 0) {
        cout << "-";
        sum = -sum;
    }
    if (!sum){
        cout << 0;
    }
    while (sum) {
        result.push(sum % 10);
        sum /= 10;
    }
    length = result.size();
    while (!result.empty()) {
        if (result.size() != length && result.size() % 3 == 0) {
            cout << ",";
        }
        cout << result.top();
        result.pop();
    }
}
