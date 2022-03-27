#include<bits/stdc++.h>
using namespace std;
int n,m;
bool to[100010<<1];
string name[100010<<1];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>to[i]>>name[i];
	}
	
	int now = 1;
	for(int i=1;i<=m;i++)
	{
		int op;
		cin>>op;
		if(op==0&&to[now]==0 || op==1&&to[now]==1)
		{
			int x;
			cin>>x;
			while(x>now)
				now += n;
			now = now - x;
		}
		else
		{
			int x;
			cin>>x;
			now = now + x;
			while(now>n)
				now %= n;
		}	
	}
	cout<<name[now];
	
		
	
}