#include<bits/stdc++.h>
#include<queue>
using namespace std;
queue<int> a;
int main()
{
	int ans=0,n;
	cin>>n;
	a.push(n);
	while(!a.empty())
	{
		int x;
		x=a.front();
		a.pop();
		int num=0;
		for(int i=1;i<=x/2+1;i++)
		{
			if(x==i)
			break;
			if(x%i==0)
			{
				num++;
				a.push(i);
			}
		}
		if(num==0)
		ans+=2;
	}
	cout<<ans;
}
