#include <string>
#include <vector>

using namespace std;

long long times[360001];

int StartTime(string s)
{
    int time = 0;

    time += (s[0] - 48) * 60 * 60 * 10;
    time += (s[1] - 48) * 60 * 60;
    time += (s[3] - 48) * 60 * 10;
    time += (s[4] - 48) * 60;
    time += (s[6] - 48) * 10;
    time += (s[7] - 48);

    return time;
}

int EndTime(string s)
{
    int time = 0;

    time += (s[9] - 48) * 60 * 60 * 10;
    time += (s[10] - 48) * 60 * 60;
    time += (s[12] - 48) * 60 * 10;
    time += (s[13] - 48) * 60;
    time += (s[15] - 48) * 10;
    time += (s[16] - 48);

    return time;
}

string ToString(int num)
{
    int seconds = num % 60;
    int minutes = (num / 60) % 60;
    int hours = (num / 60) / 60;

    string s = "00:00:00";

    s[0] = (hours / 10 + 48);
    s[1] = (hours % 10 + 48);
    s[3] = (minutes / 10 + 48);
    s[4] = (minutes % 10 + 48);
    s[6] = (seconds / 10 + 48);
    s[7] = (seconds % 10 + 48);

    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    for (int i = 0; i < logs.size(); i++)
    {
        int start = StartTime(logs[i]);
        int end = EndTime(logs[i]);

        times[start]++;
        times[end]--;
    }

    for(int i = 1; i < 360001; i++)
    {
	    times[i] += times[i-1];
    }

    for (int i = 1; i < 360001; i++)
    {
        times[i] += times[i - 1];
    }

    int start = StartTime(play_time);
    int adv = StartTime(adv_time);

    long long val = 0, ans = 0;
    
    for(int i = 0; i <= start - adv; i++)
    {
        if (val < times[i + adv-1] - times[i-1])
        {
            val = times[i+adv-1] - times[i-1];
            ans = i;
        }
    }

    answer = ToString(ans);

    return answer;
}