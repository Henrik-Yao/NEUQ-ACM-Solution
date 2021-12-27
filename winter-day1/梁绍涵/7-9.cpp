#include<bits/stdc++.h>
using namespace std;
struct peo
{
	int time,per;
	string name;
	int exist=1;
}p[100001];
int n,m,k=0,k1=0;
map<string,int> q; 
queue<string> que;
int main()
{
	cin>>n>>m;
	while(m--)
	{
		int num;
		string name;
		cin>>num;
		while(num--)
		{
			cin>>name;
			q[name]=k+1;
		}
		k++;
	}
	for(int i=1;i<=n;i++)
	{
		string nam;
		int t,pi;
		cin>>nam>>t>>pi;
		p[i].time=t;
		p[i].per=pi;
		p[i].name=nam;
	}
	int now=0,sumt=0;
	int circle;
	for(int i=1;i<=n;i++)
	{
		if(p[i].exist==-1) continue;
		if(now<p[i].time) now=p[i].time;
		circle=q[p[i].name];
		for(int j=1;j<=n;j++)
		{
			if(p[j].exist==-1) continue;
//			cout<<p[j].name<<" 1"<<endl;
			if(q[p[j].name]!=circle) continue;
//			cout<<p[j].name<<" 2"<<endl;
			if(now<p[j].time) continue;
//			cout<<p[j].name<<" 3"<<endl;
			cout<<p[j].name<<endl;
			sumt+=(now-p[j].time);
			if(p[j].per>=60)
			now+=60;
			else
			now+=p[j].per;
			p[j].exist=-1;
		}
	}
	printf("%.1lf",sumt*1.0/n);
	cout<<endl;
}
