#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	int n,m,f[100],sum=0;
	char c[100];
	int pd=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>f[i];
		q.push(f[i]);
	}
	while(q.size()>1)
	{
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
		q.push(x+y);
		sum=sum+x+y;
	}
	cin>>m;
	string s[100];
	char a;
	for(int q=1;q<=m;q++)
	{
		int len=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a;
			cin>>s[i];
			len=s[i].size()*f[i]+len;
		}
		//cout<<"sum"<<sum<<endl;
		//cout<<"lengh"<<len<<endl;
		pd=0;
		if(len==sum)
		{
			pd=1;
			for(int i=1;i<=n-1;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int flag=1;
					int maxx=s[i].size()>s[j].size()?s[j].size():s[i].size();
					//cout<<"maxx"<<maxx<<endl;
					for(int k=0;k<maxx;k++)
					{
						if(s[i][k]!=s[j][k])
						{
							flag=0;
						}
					}
					if(flag==1)
					{
						pd=0;
					}
				}
			}	
		}
		if(pd==1)
		{
			cout<<"Yes"<<endl;
		}
		else if(pd==0)
		cout<<"No"<<endl;
	}
	return 0;
}
