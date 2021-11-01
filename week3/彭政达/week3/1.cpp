#include <bits/stdc++.h>
using namespace std;
const int MAXN=101;
typedef struct {
	int maps[MAXN][MAXN];
	int V,E;
}Graph;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout); 
	int n;
	Graph G;
	ios::sync_with_stdio(false);
	cin>>G.V>>n>>G.E;
	int safe[MAXN];
	for(int i=0;i<n;i++)
		cin>>safe[i];
	for(int i=0;i<G.V;i++)
		for(int j=0;j<G.V;j++)
			G.maps[i][j]=0;
	for(int i=0;i<G.E;i++)
	{
		int x,y;
		cin>>x>>y;
		G.maps[x][y]=1;
		G.maps[y][x]=1;
	}
	int now,arr;
	bool flag=false;
	cin>>now>>arr;
	for(int i=0;i<n;i++)
		if(arr==safe[i])
		{
			flag=true;
			break;
		}
	if(G.maps[now][arr]==1)
		if(flag)
			cout<<"The city "<<arr<<" can arrive safely!";
		else 
			cout<<"The city "<<arr<<" is not safe!";	
	else
		if(flag)
			cout<<"The city "<<arr<<" can not arrive safely!";
		else 
			cout<<"The city "<<arr<<" is not safe!";
	return 0;
}

