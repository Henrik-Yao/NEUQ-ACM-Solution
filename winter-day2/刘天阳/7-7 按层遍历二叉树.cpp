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
void ceng(Node *root){
	queue<Node*>q;
	q.push(root);
	while(!q.empty())
	{
		Node *node = q.front();
		q.pop();
		cout << node->val << " ";
		if(node->l) q.push(node->l);
		if(node->r) q.push(node->r);
	}
}
int main()
{
	 int n;
	 cin >> n;
	 for (int i = 0; i < n; i++)	cin >> xian[i];
	 for (int i = 0; i < n; i++)	cin >> mid[i];
	 Node *root = build(n, mid, xian);
	 ceng(root);
	return 0;
}
