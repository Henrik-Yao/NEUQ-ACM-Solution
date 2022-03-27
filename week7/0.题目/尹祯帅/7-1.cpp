#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string zd[10001][2];
	for(int i=0;i<n;i++)
	{
		cin>>zd[i][0]>>zd[i][1];
	}
	while(m--)
	{
		string dc;
		cin>>dc;
		bool ju=0;
		for(int i=0;i<n;i++)
		{
			if(dc==zd[i][1]) 
			{
				cout<<zd[i][0]<<'\n';
				ju=1;
			}
		}
		if(!ju) cout<<"eh"<<'\n';
	}
	return 0;
}