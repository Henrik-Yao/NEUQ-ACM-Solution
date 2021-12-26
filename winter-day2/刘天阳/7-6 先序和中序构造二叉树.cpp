#include <bits/stdc++.h>
using namespace std;
int mid[1009], xian[1009];
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
Node* build(int n, int a[], int b[])  //aÊÇÖÐ¸ú 
{
	if(n <= 0) return NULL;
	Node *x;
	x = new Node;
	x->val = b[0];
	int t = find(a,b[0],n);
	x->l = build(t,a,b+1);
	x->r = build(n-t-1,a+t+1,b+t+1);
	return x;
}
void hou(Node *root){
	if(root == NULL) return;
	
	hou(root->l);
	hou(root->r);
	cout << root->val << " ";
}
int main()
{
	 int n;
	 cin >> n;
	 for (int i = 0; i < n; i++)	cin >> xian[i];
	 for (int i = 0; i < n; i++)	cin >> mid[i];
	 Node *root = build(n, mid, xian);
	 hou(root);
	return 0;
}
