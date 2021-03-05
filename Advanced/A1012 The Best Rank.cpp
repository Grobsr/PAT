#include <iostream>
#include <algorithm>

using namespace std;

const int STUDENT_MAX_N = 2010;//最大学生人数
const int RANK_MAX_N = 1000000;//所有学生所有学科的排名数
const string items = "ACME";//学科代码常量数组

int current;//当前进行排序的学科
int rankRes[RANK_MAX_N][4] = {0};//所有学生所有学科的排名

struct student {
    int id;
    double grade[4];
} studentInfo[STUDENT_MAX_N];//学生信息数组

//当前学科成绩高的排在前面
bool cmpGrade(student a, student b) {
    return a.grade[current] > b.grade[current];
}

int main() {
    int numOfStudents, numOfTo_CheckStudents;
    cin >> numOfStudents >> numOfTo_CheckStudents;
    //读入学生的学号和各科成绩，计算平均分
    for (int i = 0; i < numOfStudents; ++i) {
        cin >> studentInfo[i].id
            >> studentInfo[i].grade[1]
            >> studentInfo[i].grade[2]
            >> studentInfo[i].grade[3];
        studentInfo[i].grade[0] = (studentInfo[i].grade[1] + studentInfo[i].grade[2] + studentInfo[i].grade[3])
                                  / 3.0 + 0.5;
    }
    //计算每个学生每一科的排名
    for (current = 0; current < 4; ++current) {
        sort(studentInfo, studentInfo + numOfStudents, cmpGrade);
        rankRes[studentInfo[0].id][current] = 1;//排序之后第一个学生排名为1
        for (int i = 1; i < numOfStudents; ++i) {
            //成绩相等则排名一致
            if (studentInfo[i].grade[current] == studentInfo[i - 1].grade[current]) {
                rankRes[studentInfo[i].id][current] = rankRes[studentInfo[i - 1].id][current];
            } else {
                //成绩不等则排名等于下标+1
                rankRes[studentInfo[i].id][current] = i + 1;
            }
        }
    }
    int checkingId, best;
    for (int i = 0; i < numOfTo_CheckStudents; ++i) {
        cin >> checkingId;
        //如果查询的下标不存在输出"N/A"
        if (!rankRes[checkingId][0]) {
            cout << "N/A" << endl;
        } else {
            best = 0;
            //否则筛选出最高的排名并输出
            for (int j = 0; j < 4; ++j) {
                if (rankRes[checkingId][j] < rankRes[checkingId][best]) {
                    best = j;
                }
            }
            cout << rankRes[checkingId][best] << " " << items[best] << endl;
        }
    }
}
