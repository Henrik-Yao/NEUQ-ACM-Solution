#include<bits/stdc++.h>  
using namespace std;
const int maxn=1e4+10;
vector<int> ves[maxn];
int main(){
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		ves[a].push_back(b);
		ves[b].push_back(a);
	}
	cin>>k;
	while(k--)
	{
		int f[maxn]={0};
	    bool p=1;
		int np;
		cin>>np;
		for(int i=1;i<=np;i++)
		{
			int x;
			cin>>x;
			f[x]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]==0){
				for(int j=0;j<ves[i].size();j++)
				{
					if(f[ves[i][j]]==0) p=0;
				}
			}
		}
		if(p==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
