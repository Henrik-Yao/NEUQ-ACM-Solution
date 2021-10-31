#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,-1,0,1};        
int dy[4]={-1,0,1,0};
int a[1009][1009],genx[1009][1009],geny[1009][1009],ans[1009][1009];
bool vis[1009][1009];     
int sum,n,m,start_x,start_y;
void search(int x,int y)
{
	if (x < 1 || x > n || y < 1 || y > n || vis[x][y]) return;   
	if (ans[x][y]) return;     
	sum++;       
	vis[x][y] = 1;        
	genx[x][y] = start_x;
	geny[x][y] = start_y;
	for (int i = 0; i < 4; i++)   
		if (a[x+dx[i]][y+dy[i]] != a[x][y]) search(x+dx[i],y+dy[i]);
}
int main()
{
	cin>>n>>m;      
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			{
				char c;
                cin>>c;
                a[i][j]=c;
			}
			
	for (int k = 1; k <= m; k++)
		{
			cin>>start_x>>start_y;     
			if (ans[genx[start_x][start_y]][geny[start_x][start_y]])  
				{
					cout<<ans[genx[start_x][start_y]][geny[start_x][start_y]]<<endl;
					continue;
				}
			sum = 0;
			search(start_x,start_y);
			ans[start_x][start_y] = sum;
			cout<<sum<<endl;    
		}
		return 0;    
} 

