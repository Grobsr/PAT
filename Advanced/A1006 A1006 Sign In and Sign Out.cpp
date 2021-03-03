#include <iostream>

using namespace std;

int main() {
    int numOfRecords;
    cin >> numOfRecords;
    //定义最早最晚的时间以及相应的Id
    string earliestInTime = "24:60:60", earliestInId, latestOutTime = "00:00:00", latestOutId;
    string currentId, currentInTime, currentOutTime;
    for (int i = 0; i < numOfRecords; ++i) {
        cin >> currentId >> currentInTime >> currentOutTime;
        //当前进教室的时间早于已记录的最早时间
        if (currentInTime < earliestInTime){
            earliestInTime = currentInTime;//更新时间
            earliestInId = currentId;//更新Id
        }
        //当前出教室的时间晚于已记录的最晚时间
        if (currentOutTime > latestOutTime){
            latestOutTime = currentOutTime;//更新时间
            latestOutId = currentId;//更新Id
        }
    }
    cout << earliestInId << " " << latestOutId;
}
