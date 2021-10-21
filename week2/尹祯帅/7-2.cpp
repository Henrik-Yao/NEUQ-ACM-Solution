#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,q,i;
	int c;
	cin>>n>>m;
	int a[10001],b[10001];
	bool jud[n+1],ju;
	for(i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
	}
	cin>>k;
	for(int j=0;j<k;j++)
	{
		ju=1;
		memset(jud,1,sizeof(jud));
		cin>>q;
		for(i=0;i<q;i++)
		{
			cin>>c;
			jud[c]=0;
		}
		for(i=0;i<m;i++)
		{
			if(jud[a[i]]&&jud[b[i]])
			{
				cout<<"NO"<<'\n';
				ju=0;
				break;
			}
		}
		if(ju)
		cout<<"YES"<<'\n';
	}
	return 0;
}