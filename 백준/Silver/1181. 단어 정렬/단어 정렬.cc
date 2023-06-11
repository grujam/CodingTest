#include <iostream>
#include <set>

using namespace std;

struct cmp
{
	 bool operator()(const string &a, const string &b) const
	{
		 if (a.length() == b.length())
			 return a < b;
		 else
			 return a.length() < b.length();
	}
};

int main()
{
	set<string, cmp> st;
	string s;
	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> s;
		st.insert(s);
	}

	for(auto &c : st)
	{
		cout << c << endl;
	}

	return 0;
}