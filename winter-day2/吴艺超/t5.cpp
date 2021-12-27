#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int n,x,s,m;
char ch;
int a[100];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch>>x;
		a[i]=x;
		q.push(x);
	}
	while(q.size()>1)
	{
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		s=s+x+y;
		q.push(x+y);
	}
	cin>>m;
	while(m--)
	{
		string str[100];
		int s1=0;
		for(int i=0;i<n;i++)
		{
			cin>>ch>>str[i];
			s1=s1+str[i].size()*a[i];
		}
		if(s==s1)
		{
			bool dge=1;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					int flag=0;
					int len = min(str[i].size(),str[j].size());
					for(int k=0;k<len;k++)
						if(str[i][k]!=str[j][k])
							flag=1;
						if(flag==0)
							{
								dge=false;
							}
				}
			}
			if(dge)
				cout<<"Yes"<<endl;
			else 
				cout<<"No"<<endl;
		}
		else cout<<"No"<<endl;
	}
	return 0;
}
