#include<bits/stdc++.h>
using namespace std;
const int maxn = 150005;
const int maxl = 10005;
char pre[maxn], in[maxn], post[maxn],in2[maxn];
int k,level,x;
bool flag;
vector<char>postorder;
vector<char>inorder;
struct node
{
	char data='\0';
	node *l=NULL;
	node *r=NULL;
};
void rebuild(vector<char>post, vector<char>in, node* no)//重建树
{
	vector<char>inl, inr;
	vector<char>postl, postr;
	if (post.size() == 0)return;
	char root = post[post.size() - 1];
	post.pop_back();
	no->data = root;//赋值失败？？
	//拆中序遍历
	bool flag = 0;
	for (int i = 0; i < in.size(); i++)
	{
		if (in[i] == root)
		{
			flag = 1;
			continue;
		}
		if (!flag) inl.push_back(in[i]);//左
		else inr.push_back(in[i]);//右
	}
	//拆后序遍历
	for (int i = 0; i < post.size(); i++)
	{
		if (i < inl.size())
		{
			postl.push_back(post[i]);
		}
		else
		{
			postr.push_back(post[i]);
		}
	}
	if (inl.size() > 0)
	{
		no->l = new node;
		rebuild(postl, inl, no->l);
	}
	if (inr.size() > 0)
	{
		no->r = new node;
		rebuild(postr, inr, no->r);
	}
}
void preorder(node* no,int floor)
{
	if (no != NULL)
	{
		pre[k++] = no->data;//先根
		//cout << no->data << " "<<floor<<endl;
		preorder(no->l,floor+1);//再左右
		preorder(no->r,floor+1);
	}
	else
	{
		level = max(level, floor);
	}
}
void checkin(node* no)
{
	if (no != NULL)
	{
		checkin(no->l);//先左
		in2[x++] = no->data;//再根
		checkin(no->r);
	}
}
void remove_tree(node*rt)//删除树
{
	if (rt == NULL)return;
	remove_tree(rt->l);
	remove_tree(rt->r);
	delete rt;
}
int main()
{
	string spre, sin, spost;//先序中序后序
	while (cin >> spost)
	{
		
		cin >> sin;
		flag = 1;
		int n = spost.size();//节点数
		for (int i = 0; i < n; i++)
		{
			post[i] = spost[i];
			in[i] = sin[i];
			postorder.push_back(spost[i]);
			inorder.push_back(sin[i]);
		}
		node* rt = new node;
		rt->data = postorder.back();
		rebuild(postorder, inorder, rt);//建树
		k = 0,level=0;
		preorder(rt,level);
		x = 0;
		checkin(rt);//建立一个用于检验的树
		for (int i = 0; i < n; i++)
		{
			if (in[i] != in2[i])
			{
				flag = 0; break;
			}
		}
		if (flag)
		{
			cout << level - 1 << endl;
			for (int i = 0; i < k; i++)
			{
				printf("%c", pre[i]);
			}
			cout << endl;
		}
		else cout << "INVALID" << endl;
		remove_tree(rt);
		postorder.clear();
		inorder.clear();
	}
	return 0;
}
