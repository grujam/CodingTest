#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    Node(string name)
	    : name(name)
    {
        children.clear();
    }

    void AddChild(Node* node)
    {
        children.push_back(node);
    }

    string name;
    vector<Node*> children;
};

Node* CheckChildren(const Node* root, const string InName)
{
	for(Node* node : root->children)
	{
        if (node->name == InName)
            return node;
	}

    return nullptr;
}

void Print(Node* node, int level)
{
    sort(node->children.begin(), node->children.end(), [](Node* a, Node* b)
    {
    	return a->name < b->name;
    });

    for(Node* nd : node->children)
    {
	    for(int i = 0; i < level; i++)
	    {
            cout << "--";
	    }
        cout << nd->name << '\n';
        Print(nd, level + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    Node* root = new Node("Root");

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        Node* current = root;
        for(int j = 0; j < num; j++)
        {
            string name;
            cin >> name;

            Node* node = CheckChildren(current, name);
            if (node == nullptr)
            {
                node = new Node(name);
                current->AddChild(node);
            }
            current = node;
        }
    }

    Print(root, 0);

    return 0;
}
