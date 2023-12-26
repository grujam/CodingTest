#include <iostream>
#include <map>

using namespace std;

int N;

map<int, int> inorder;
int postorder[100001];
bool check[100001];

void Preorder(int root, int postidx, int pivot)
{
    //root = root 값, postidx = postorder에서의 index, pivot 우측 기준

    if (check[root] == true)
        return;

    cout << root << " ";
    check[root] = true;

    //LEFT
    int leftidx = postidx - (pivot - inorder[root]);
    if (leftidx >= 0)
        Preorder(postorder[leftidx], leftidx, inorder[root]);

    //RIGHT
    int rightidx = postidx - 1;
    if (rightidx >= 0)
        Preorder(postorder[rightidx], rightidx, pivot);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        inorder[num] = i;
    }

    for (int i = 0; i < N; i++)
        cin >> postorder[i];

	int root = postorder[N - 1];

    Preorder(root, N - 1, N);

    return 0;
}
