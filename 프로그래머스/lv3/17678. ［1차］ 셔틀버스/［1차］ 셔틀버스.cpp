#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    int busTime = 540;
    int nAnswer, idx = 0;
    

    vector<int> v;

    for(string& t : timetable)
    {
        int toTime = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
        v.push_back(toTime);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
    {
        int nCrewsOnBus = 0;

        while(nCrewsOnBus < m && idx < v.size())
        {
	        if(v[idx] <= busTime)
	        {
                nCrewsOnBus++;
                idx++;
	        }
            else
                break;
        }

        if(i == n - 1)
        {
            if (nCrewsOnBus < m)
                nAnswer = busTime;
            else
                nAnswer = v[idx-1] - 1;
        }

        busTime += t;
    }

    int hour = nAnswer / 60;
    int minute = nAnswer % 60;

    if (hour < 10)
        answer += "0" + to_string(hour);
    else
        answer += to_string(hour);

    answer += ":";

    if (minute < 10)
        answer += "0" + to_string(minute);
    else
        answer += to_string(minute);

    return answer;
}