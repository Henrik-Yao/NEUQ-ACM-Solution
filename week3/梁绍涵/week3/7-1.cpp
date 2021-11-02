#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f
using namespace std;
int m,n,k,s,d;
bool sa[101];
int ma[101][101],dis[101],flag=0,vis[101];
void dfs(int t)
{
	 if(t==d) 
	 {
	 	flag=1;
	 	
	 	return;
	 }
	 for(int i=0;i<m;i++)
	 {
//	 	cout<<i<<endl;
	 	if(!sa[i]||vis[i]||ma[t][i]==0) continue;
	 	vis[i]=1;
	 	dfs(i);
	 	vis[i]=0;
	 }
	 return;
}
int main()
{
	cin>>m>>n>>k;
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		sa[num]=1;
	}
	memset(ma,0,sizeof(ma));
	for(int i=1;i<=k;i++)
	{
		int ui,vi;
		cin>>ui>>vi;
		ma[ui][vi]=1;
		ma[vi][ui]=1;
	}
	cin>>s>>d;
	if(!sa[d])
	{
		cout<<"The city "<<d<<" is not safe!";
		return 0;
	}
	dfs(s);
	if(flag==0)
	cout<<"The city "<<d<<" can not arrive safely!";
	else
	cout<<"The city "<<d<<" can arrive safely!";
}
