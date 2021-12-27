#include<bits/stdc++.h>
using namespace std;
queue <int> q[105];
int main()
{
	int n,x,cnt=1;
	cin>>n;
	cin>>x;
	q[1].push(x);
	for(int i=1;i<n;i++)
	{
		bool judge=false;
		cin>>x;
		for(int i=1;i<=cnt;i++)
		{
			if(q[i].back()>x)
			{
				q[i].push(x);
				judge=true;
				break;
			}
		}
		if(!judge)
		q[++cnt].push(x);
	}
	int i=1;
	int t[105];
	while(!q[1].empty())
	{
		t[i++]=q[1].front();
		q[1].pop();
	}
	for(int j=1;j<i-1;j++)
	cout<<t[j]<<" ";
	cout<<t[i-1]<<endl;
	cout<<cnt;
}
