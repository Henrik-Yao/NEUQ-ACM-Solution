#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int number[1005] = { 0 };
typedef struct TNode
{
	int data;
	TNode* L, * R;
}*Tree;
int maxhigh = 0;
void Build(Tree& T,int n,int max,int high)
{
	if (number[n] && n <= max)
	{
		T = (Tree)malloc(sizeof(TNode));
		T->data = number[n];
		T->L = NULL;
		T->R = NULL;
		if (high > maxhigh) maxhigh = high;
		Build(T->L, 2 * n, max, high + 1);
		Build(T->R, 2 * n + 1, max, high + 1);
	}
}
queue<int>Q;
void Inorder(Tree T)
{
	if (T)
	{
		Inorder(T->L);
		Q.push(T->data);
		Inorder(T->R);
	}
}
int main() 
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, i;
		stack<int> S;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> number[i];
		}
		Tree T;
		maxhigh = 0;
		Build(T, 1, n, 1);
		Inorder(T);
		cout << Q.front();
		Q.pop();
		while (Q.size())
		{
			cout << " " << Q.front();
			Q.pop();
		}
		cout << endl;
		cout << maxhigh << endl;
	}
	return 0;
}