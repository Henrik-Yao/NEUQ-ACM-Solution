#include <bits/stdc++.h>
using namespace std;
int mid[1009], hou[1009];
struct Node{
	Node *l, *r;
	int val;
	Node(){
		l = r = NULL;
	}
};
int find(int a[], int x, int n)
{
	for (int i = 0; i < n; i++)
	{
		if(a[i] == x) return i;
	}
}
Node* build(int n, int a[], int b[])
{
	if(n <= 0) return NULL;
	Node *x;
	x = new Node;
	x->val = b[n-1];
	int t = find(a,b[n-1],n);
	x->l = build(t,a,b);
	x->r = build(n-t-1,a+t+1,b+t);
	return x;
}
void qian(Node *root){
	if(root == NULL) return;
	cout << root->val << " ";
	qian(root->l);
	qian(root->r);
}
int main()
{
	 int n;
	 cin >> n;
	 for (int i = 0; i < n; i++)	cin >> hou[i];
	 for (int i = 0; i < n; i++)	cin >> mid[i];
	 Node *root = build(n, mid, hou);
	 qian(root);
	return 0;
}
