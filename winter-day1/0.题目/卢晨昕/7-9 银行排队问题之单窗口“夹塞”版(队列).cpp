#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
map<string,int>mmp;//�����Ǹ�Ȧ��
struct node
{
	string name;
	int t,p;
}nodes[100005];
bool vis[100005];
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int l;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			string name;
			cin>>name;
			mmp[name]=i+1;
		}
	}
	int tot=m+1;
	for(int i=0;i<n;i++)
	{
		cin>>nodes[i].name>>nodes[i].t>>nodes[i].p;
		if(!mmp[nodes[i].name])mmp[nodes[i].name]=tot++;
		if(nodes[i].p>60)nodes[i].p=60;
	}
	int ans=0;//�ȴ�ʱ�� 
	int time=nodes[0].t+nodes[0].p;//����ʱ 
	queue<node>q;
	q.push(nodes[0]);
	vis[0]=true;
	while(!q.empty())
	{
		node now=q.front();
		cout<<now.name<<endl;
		q.pop();
		bool flag=false;
		for(int i=1;i<n;i++)//Ѱ���������� 
		{
			if(vis[i])continue;
			if(nodes[i].t>time)break;
			if(mmp[nodes[i].name]==mmp[now.name])//�� 
			{
				q.push(nodes[i]);
				vis[i]=true;
				flag=true;
				ans+=time-nodes[i].t;//���ϸ����ѵȴ���ʱ�� 
				time+=nodes[i].p;//����ʱ����������õ�ʱ�� 
				break;
			}
		}
		if(!flag)//������
		{
			for(int i=1;i<n;i++)//Ѱ����һ���� 
			{
				if(vis[i])continue;
				q.push(nodes[i]);
				vis[i]=true;
				ans+=max(0,time-nodes[i].t);//���ϸ��˵ĵȴ�ʱ�� 
				if(nodes[i].t>time)time=nodes[i].t;//�ø������õ�ʱ���������ʱ 
				time+=nodes[i].p;
				break;
			}
		}
	}
	printf("%0.1lf",1.0*ans/n);
	return 0;
}
