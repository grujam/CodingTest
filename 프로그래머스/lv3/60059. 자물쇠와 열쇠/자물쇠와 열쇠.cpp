#include <string>
#include <vector>

using namespace std;

bool Match(vector<vector<int>> key, vector<vector<int>> lock, int x, int y)
{
    int keySize = key.size();
	for(int i = 0; i < lock.size(); i++)
	{
		for(int j = 0; j < lock.size(); j++)
		{
			if(i - y > -1 && i - y < keySize && j - x > -1 && j - x < keySize)
				lock[i][j] += key[i - y][j - x];

			if (lock[i][j] != 1)
				return false;
		}
	}
	return true;
}

void Turn(vector<vector<int>>& key)
{
	int keySize = key.size();

	vector<vector<int>> tmp = key;

	for(int j = 0; j < keySize; j++)
	{
		for(int i = 0; i < keySize; i++)
		{
			key[i][j] = tmp[keySize - j - 1][i];
		}
	}
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

	int keySize = key.size();
	int lockSize = lock.size();

	for(int i = 0; i < 4; i++)
	{
		for(int x = -keySize + 1; x < lockSize + keySize - 1; x++)
		{
			for (int y = -keySize + 1; y < lockSize + keySize - 1; y++)
			{
				bool check = Match(key, lock, x, y);
				if (check == true)
					return true;
			}
		}
		Turn(key);
	}

    return answer;
}