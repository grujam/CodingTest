#include <iostream>
#include <vector>

using namespace std;

int Leaf = 0;

vector<struct Node*> nodes;

struct Node
{
	Node(int data)
	{
		this->data = data;
		children.clear();
	}

	int data;
	vector<Node*> children;
};

void CountLeaf(Node* node, int del)
{
	if(node->children.empty())
	{
		Leaf++;
		return;
	}

	if(node->children.size() == 1 && node->children[0]->data == del)
	{
		Leaf++;
		return;
	}

	for(int i = 0; i < node->children.size(); i++)
	{
		if (node->children[i]->data == del)
			continue;

		CountLeaf(node->children[i], del);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, nd, del;

	cin >> N;

	Node* root = nullptr;

	for(int i = 0; i < N; i++)
	{
		Node* node = new Node(i);

		nodes.push_back(node);
	}

	for(int i = 0; i < N; i++)
	{
		cin >> nd;
		if (nd == -1)
			root = nodes[i];
		else
			nodes[nd]->children.push_back(nodes[i]);
	}

	cin >> del;

	if(root->data == del)
	{
		cout << 0;
		return 0;
	}

	CountLeaf(root, del);

	cout << Leaf;

	return 0;
}