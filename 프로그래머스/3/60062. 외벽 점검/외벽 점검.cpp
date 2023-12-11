#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer;
    weak.size() == dist.size() ? answer = dist.size() : answer = dist.size() + 1;
    
    vector<int> node_dist;
    for (int i = 0; i < weak.size(); i++)
    {
        node_dist.push_back((weak[(i + 1) % weak.size()] + n - weak[i]) % n);
    }
    
    sort(dist.begin(), dist.end());
    
    do
    {
        for (int i = 0; i < node_dist.size(); i++)
        {
            int node_num = 0;
            int node_idx = i;
            int ans = 0;

            for (int j = 0; j < dist.size(); j++)
            {
                int d = dist[j];
                ans++;
                node_num++;
                while (d >= node_dist[node_idx] && node_num < node_dist.size())
                {
                    d -= node_dist[node_idx];
                    node_num++;
                    node_idx = (node_idx + 1) % node_dist.size();
                }
                node_idx = (node_idx + 1) % node_dist.size();

                if (node_num == node_dist.size())
                {
                    answer = min(ans, answer);
                }
            }
        }
    }while (next_permutation(dist.begin(), dist.end()));

    answer == dist.size() + 1 ? answer = -1 : answer;
    return answer;
}