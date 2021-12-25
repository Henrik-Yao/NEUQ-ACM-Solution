#include<bits/stdc++.h>
using namespace std;
queue<int> q[100];
int ans=0;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,flag=0;
		cin>>x;
		for(int j=1;j<=ans;j++)
		{
			if(q[j].back()>x)
			{
				q[j].push(x);
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			ans++;
			q[ans].push(x);
		}
	}
	for(int i=1;i<=ans;i++)
	{
		if(q[i].back()==1)
		{
			while(!q[i].empty())
			{
				cout<<q[i].front();
				q[i].pop();
				if(!q[i].empty())cout<<" ";
			}
			cout<<endl;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
