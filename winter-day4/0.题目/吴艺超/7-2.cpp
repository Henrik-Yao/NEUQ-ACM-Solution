#include <bits/stdc++.h>
using namespace std;
int d[205][205],n,m;
int main(){
	while(cin>>n>>m)
	{
		memset(d,0x3f,sizeof(d));
		for(int i=0;i<n;i++)
			d[i][i]=0;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			for(int j=1;j<=b;j++)
			{
				int x;
				cin>>x;
				d[a][x]=1;
			}
		}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(d[x][y]>100000)
			{
				cout<<"connection impossible"<<endl;
			}
			else cout<<d[x][y]<<endl;
		}
	}
    return 0;    
}
