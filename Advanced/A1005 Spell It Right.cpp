#include <iostream>

using namespace std;


int main(){
    //定义常量数组
    const string digits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string input;
    cin >> input;
    int sum = 0;
    //求输入的长数字每一位的和
    for (char i : input) {
        sum += i - '0';
    }
//    for (int i = 0; i < input.length(); ++i) {
//        sum += input[i] - '0';
//    }
    string res = to_string(sum);//将结果转化成字符串
    cout << digits[res[0] - '0'];//第一位单独处理
    //输出结果的每一位
    for (int i = 1; i < res.length(); ++i) {
        cout <<" " << digits[res[i] - '0'];
    }
}
