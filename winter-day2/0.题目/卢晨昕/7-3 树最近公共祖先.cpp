//��������ֵܵĴ�����ʽ
#include<bits/stdc++.h>

using namespace std;
int t;
int ans;
map<int,int>v;
struct node
{
	node *child=NULL;//��¼�õ�ĵ�һ�����ӣ������Ķ��Ӽǳɸö��ӵ��ֵ� 
	node *brother=NULL;//��¼�õ�ĵ�һ���ֵܣ��ڶ������ֵ��ɵ�һ���ֵܼ�¼ 
	node *fa=NULL;
	int len=0;
	int val=0;
};
node *creat()
{
	node *root=new node();
	root->child=NULL;
	root->brother=NULL;
	int a;
	cin>>a;
	if(a==0)root=NULL;
	else
	{
		root->val=a;
		root->child=creat();//child��root�Ĵ��� 
		root->brother=creat();//brother��next���ֵ� 
	}
	return root;
}
void findfa(node *x,node *fa)
{
	if(x==NULL)return;
	x->fa=fa;
	findfa(x->child,x);//�Լ����ӵĸ��׾����Լ� 
	findfa(x->brother,fa);//�Լ��ֵܺ��Լ�������ͬ 
}
void find(node *z,int a,int b,node *&x,node *&y)
{
	if(z==NULL)return;
	if(z->val==a)x=z;
	if(z->val==b)y=z;
	find(z->child,a,b,x,y);
	find(z->brother,a,b,x,y);
}
void dfs1(node *x)
{
	if(x==NULL)return;
	v[x->val]=1;
	dfs1(x->fa);
}
void dfs2(node *y)
{
	if(y==NULL)return;
	if(v[y->val]!=0)
	{
		ans=y->val;
		return;
	}
	dfs2(y->fa);
}
int main()
{
	cin>>t;
	while(t--)
	{
		v.clear();
		
		int a,b;
		node *bt=creat();
		ans=bt->val;
		findfa(bt,NULL);
		cin>>a>>b;
		node *x,*y;
		find(bt,a,b,x,y);
		dfs1(x);
		dfs2(y);
		cout<<ans<<endl;
		delete bt; 
	}
	return 0;
}
