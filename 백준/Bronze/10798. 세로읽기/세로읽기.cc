#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	string arr[5];
	int lengths[5];
	int len = 0;

	for(int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		lengths[i] = arr[i].length();
		len = max(len, static_cast<int>(arr[i].length()));
	}

	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if (lengths[j] < i + 1)
				continue;
			cout << arr[j][i];
		}
	}




	return 0;
}