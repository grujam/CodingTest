#include <iostream>

using namespace std;

int arr[101];
int op[4];

int N;

enum
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
};

int mx = -1000000001;
int mn = 1000000001;

void dfs(int sum, int idx, int oper)
{
	switch(oper)
	{
	case ADD:
		sum += arr[idx];
		break;
	case SUBTRACT:
		sum -= arr[idx];
		break;
	case MULTIPLY:
		sum *= arr[idx];
		break;
	case DIVIDE:
		sum /= arr[idx];
		break;
	}

	if(idx == N-1)
	{
		mx = max(mx, sum);
		mn = min(mn, sum);
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		if(op[i] > 0)
		{
			op[i]--;
			dfs(sum, idx + 1, i);
			op[i]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < 4; i++)
		cin >> op[i];

	for (int i = 0; i < 4; i++)
	{
		if (op[i] > 0)
		{
			op[i]--;
			dfs(arr[0], 1, i);
			op[i]++;
		}
	}

	cout << mx << endl << mn;

	return 0;
}