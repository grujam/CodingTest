#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    Node(int idx)
        : idx(idx)
    {
	    
    }

    int idx;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class LinkedList
{
public:
    LinkedList() {};

    void AddList(Node* node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void SetCurrent(int n)
    {
        current = head;
        for (int i = 0; i < n; i++)
            current = current->next;
    }

    void Move(char c, int n)
    {
        switch(c)
        {
        case 'U':
            for (int i = 0; i < n; i++)
                current = current->prev;
            break;
        case 'D':
            for (int i = 0; i < n; i++)
                current = current->next;
            break;
        }
    }

    void Remove()
    {
        s.push(current);

        if(current->next != nullptr)
            current->next->prev = current->prev;
        
        if (current->prev != nullptr)
            current->prev->next = current->next;

        if (current->next == nullptr)
            current = current->prev;
        else
            current = current->next;
    }

    void Undo()
    {
        Node* top = s.top();
        s.pop();

        if (top->prev != nullptr)
            top->prev->next = top;
        if (top->next != nullptr)
            top->next->prev = top;
    }

    int GetStackSize()
    {
        return s.size();
    }

    int GetStackTop()
    {
        return s.top()->idx;
    }

    void RemoveStackTop()
    {
        s.pop();
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;

    stack<Node*> s;
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    LinkedList list;

    for (int i = 0; i < n; i++)
    {
        answer.push_back('O');
        Node* node = new Node(i);
        list.AddList(node);
    }

    list.SetCurrent(k);

    for(const string& s : cmd)
    {
        char c = s[0];

        if (c == 'C')
            list.Remove();
        else if (c == 'Z')
            list.Undo();
        else
        {
            int num = stoi(s.substr(2));
            list.Move(c, num);
        }
    }

    int num = list.GetStackSize();

    for (int i = 0; i < num; i++)
    {
        int idx = list.GetStackTop();
        list.RemoveStackTop();

        answer[idx] = 'X';
    }

    return answer;
}