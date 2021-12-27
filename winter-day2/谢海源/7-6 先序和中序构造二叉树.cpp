#include<bits/stdc++.h>
using namespace std;
const int maxn = 150005;
const int maxl = 10005;
int apre[maxn], ain[maxn], apost[maxn];
int k,n;
bool flag;
list<int>preorder;
list<int>inorder;
struct node
{
	int data = -100;
	int pos = -1;//首位置
	int sta = -1;
	node* l = NULL;
	node* r = NULL;
};
void rebuild(list<int>pre, list<int>in, node* no)//重建树
{
	list<int>inl, inr;
	list<int>prel, prer;
	if (pre.size() == 0|| no->pos<0)return;
	int x = no->pos;
	int y = no->sta;
	int root = apre[x];//根在前面
	pre.pop_front();//弹出首元
	no->data = root;
	//拆中序遍历
	bool flag = 0;
	for (int i = 0; i < in.size(); i++)//长度
	{
		if (ain[y+i] == root)
		{
			flag = 1;
			continue;
		}
		if (!flag) inl.push_back(ain[y+i]);//左
		else inr.push_back(ain[y+i]);//右
	}
	//拆先序遍历
	for (int i = 0; i<pre.size(); i++)//长度
	{
		if (i< inl.size())
		{
			prel.push_back(apre[x+1+i]);
		}
		else
		{
			prer.push_back(apre[x+1+i]);
		}
	}

	if (prel.size() > 0&& inl.size() > 0)
	{
		no->l = new node;
		no->l->pos = x +1;
		no->l->sta = y;
		rebuild(prel, inl, no->l);
	}
	if (prer.size() > 0 && inr.size() > 0)
	{
		no->r = new node;
		no->r->pos = x + prel.size() + 1;
		no->r->sta = y + inl.size() + 1;
		rebuild(prer, inr, no->r);
	}
}
void postorder(node* no)
{
	if (no != NULL)
	{
		postorder(no->l);//先左右
		postorder(no->r);
		apost[k++] = no->data;//再根
		//cout << no->data << endl;
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
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> apre[i];
		preorder.push_back(apre[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ain[i];
		inorder.push_back(ain[i]);
	}
	node* rt = new node;
	rt->data = apre[0];
	rt->pos = 0;//从首位开始
	rt->sta = 0;//从首位开始
	rebuild(preorder, inorder, rt);//建树
	k = 0;
	postorder(rt);//后序遍历
	for (int i = 0; i < k; i++)cout << apost[i] << " ";
	remove_tree(rt);
	return 0;
}
