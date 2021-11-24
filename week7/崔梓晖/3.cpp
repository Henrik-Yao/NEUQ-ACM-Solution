#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	bool vis[1001];
	while(getline(cin,a))
	{
        memset(vis,0,sizeof(vis));
		getline(cin,b);
		for(int i=0;i<b.size();i++)
		{
			vis[b[i]]=1;
		}
		for(int i=0;i<a.size();i++)
		{
			if(vis[a[i]]==1)
			{
				continue;
			}
			else
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
