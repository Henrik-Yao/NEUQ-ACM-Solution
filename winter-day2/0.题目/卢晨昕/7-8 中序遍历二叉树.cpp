//7-8 ÖÐÐò±éÀú¶þ²æÊ÷
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int t;
int n;
int maxn=0;
int num[1005];
struct node
{
	node *l,*r;
	int val;
	int step;
};
void build(node *root,int now,int step)
{
	if(now<n)
	{
		root->val=num[now];
		root->step=step;
		if(step>maxn)maxn=step;
		if(2*now+1<n&&num[now*2+1]!=0)
		{
			root->l=new node();
			build(root->l,now*2+1,step+1);
		}
		if(2*now+2<n&&num[now*2+2]!=0)
		{
			root->r=new node();
			build(root->r,now*2+2,step+1);
		}
	}
}
int hi=0;
void vis(node *a)
{
	if(a==NULL)return;
	vis(a->l);
	if(hi==0)
	{
		cout<<a->val;
		hi=1;
	}
	else if(hi==1)cout<<" "<<a->val;
	vis(a->r);
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(num,0,sizeof(num));
		maxn=0;
		hi=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>num[i];
		node *bt=new node();
		build(bt,0,1);
		vis(bt);
		cout<<endl;
		if(t)cout<<maxn<<endl;
		else cout<<maxn;
	}
	return 0;
}
