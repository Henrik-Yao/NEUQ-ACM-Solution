#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int maxl = 10005;
int ain[maxn], x[maxn];
int t, n,k,level;
struct node
{
	int data = 0;
	int num = -1;
	node* l = NULL;
	node* r = NULL;
};
void build(node* rt)
{
	int y = rt->num;
	rt->data = x[y];
	if (rt->data == 0)
	{
		rt=NULL;
		return;//最后一层
	}
	if (y * 2 <= n&&x[y*2]!=0)
	{
		rt->l = new node;
		rt->l->num = y * 2;
		build(rt->l);
	}
	else rt->l = NULL;
	if(y*2+1 <= n && x[y * 2+1] != 0)
	{
		rt->r = new node;
		rt->r->num = y * 2 + 1;
		build(rt->r);
	}
	else rt->r = NULL;
}
void inorder(node* no)
{
	//if (no != NULL && no->data == 0) return;
	if (no != NULL)
	{
		inorder(no->l);
		ain[k++] = no->data;
		inorder(no->r);
		//cout << no->data << endl;
	}
}

int getdeep(node* rt)
{
	int l, r;
	if (rt == NULL)
		return 0;
	else {
		l = getdeep(rt->l);
		r = getdeep(rt->r);
		if (l > r)
			return l + 1;
		else return r + 1;
	}
}
void remove_tree(node* rt)//删除树
{
	if (rt == NULL)return;
	remove_tree(rt->l);
	remove_tree(rt->r);
	delete rt;
}
int main()
{
	cin >> t;
	while (t--)
	{
		memset(x, 0, sizeof(x));
		memset(ain, 0, sizeof(ain));
		scanf("%d", &n);
		for (int i = 1; i <=n; i++) scanf("%d", &x[i]);
		k = 0;
		node* rt = new node;
		rt->num = 1;
		build(rt);
		k = 0,level=0;
		inorder(rt);
		for (int i = 0; i < k-1; i++) cout << ain[i] << " ";cout << ain[k - 1]<<endl;
		cout << getdeep(rt) << endl;
		remove_tree(rt);
	}
	return 0;
}
