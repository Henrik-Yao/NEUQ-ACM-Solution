#include<bits/stdc++.h>
using namespace std;
int a[105]={};
int tree[105]={};
int s[105]={};
bool v[105]={};
int n=0,sn=0;//sn为层数，n为结点数
queue<int>que;
int x=1;
void build(int rt)//节点数
{
	tree[rt]=a[x++];
	if(tree[rt]) build(rt<<1);//左
	if(tree[rt]) build(rt<<1|1);//右
}
int main()
{
	while(cin>>a[n+1])
	{
		n++;
		v[n]=1;
	}
	sn=log(n)/log(2)+1;//层数
	build(1);
	
	que.push(1);//第一个节点
	while(!que.empty())
	{
		int top=que.front();
		sn=log(top)/log(2)+1;//从上往下数的层数
		if(v[top<<1]) que.push(top<<1);//加入队列
		if(v[top<<1|1]) que.push(top<<1|1);
		s[sn]+=tree[top];
		que.pop();//弹出首位
	}
	int amax=1;
	for(int i=1;i<=sn;i++)
	{
		if(abs(s[i])>=abs(s[amax])) amax=i;
		//cout<<s[i]<<endl;
	}
	//cout<<sn<<endl;
	cout<<amax-1<<endl;
    return 0;
}
