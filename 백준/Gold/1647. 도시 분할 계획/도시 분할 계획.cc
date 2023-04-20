#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Edge
{
	Edge(int a, int b, int val)
	{
		this->a = a;
		this->b = b;
		this->val = val;
	}

	bool operator < (Edge other)
	{
		if (this->val < other.val)
			return true;
		else
			return false;
	}

	int a;
	int b;
	int val;
};

class DisjointSet
{
public:
	DisjointSet(int node_count)
	{
		/*
			초기 상태는 각각의 요소가 따로따로 집합에 속한 상태
			-> i번째 요소는 i번째 집합에 속한다고 가정
		*/
		for (int i = 0; i < node_count; i++)
			parent.push_back(i);
	}



	// 요소 v1과 요소 v2를 합쳐준다.
	// -> v1이 속한 집합에 v2가 속한 집합을 합쳐준다.
	int Union(Edge edge)
	{
		// 각 요소의 집합(루트)를 찾는다.
		edge.a = Find(edge.a);
		edge.b = Find(edge.b);

		// 집합이 같을경우 리턴
		if (edge.a == edge.b) return 0;

		// v2의 루트를 v1의 루트로 연결시켜준다.
		// parent[v2] == v2인 상환이므로
		// v2의 집합을 v1의 루트로 연결시켜주는 형태가 된다.
		parent[edge.b] = edge.a;
		return edge.val;
	}

	// 자신이 속한 집합(루트) 반환
	int Find(int v)
	{
		if (parent[v] == v) return v;
		int tmp = Find(parent[v]);
		parent[v] = tmp;
		return tmp;
	}


private:
	// parent[i] : i번째 원소의 부모 노드의 번호
	// -> 만약 parent[i] == i일 경우 해당 원소가 집합 i의 대표 원소
	vector<int> parent;
};



int main()
{
	int N, M, a, b, c, total = 0, erase = 0, curr = 0;
	vector<Edge> edges;
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> N >> M;
		
	DisjointSet network(N);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		edges.push_back(Edge(a-1,b-1,c));
	}

	sort(edges.begin(), edges.end());

	for (int j = 0; j < M; j++)
	{
		curr = network.Union(edges[j]);
		total += curr;
		if (curr != 0) {
			erase = curr;
		}
	}
	total -= erase;
	cout << total;

	return 0;
}