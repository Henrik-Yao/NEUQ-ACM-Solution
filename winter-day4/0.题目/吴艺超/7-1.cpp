#include <bits/stdc++.h>
using namespace std;
int d[200][200],n,m;
int main(){
	while(cin>>n>>m)
	{
		memset(d,0x3f,sizeof(d));
		int sum=0,num=0,msum=2147483647;
		for(int i=0;i<n;i++)
			d[i][i]=0;
		for(int i=1;i<=m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			d[x][y]=min(d[x][y],z);
			d[y][x]=min(d[y][x],z);
		}
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		for(int i=0;i<n;i++)
		{
			sum=0;
			for(int j=0;j<n;j++)
				sum+=d[i][j];
			if(msum>sum)
			{
				msum=sum;
				num=i;
			}
		}
		cout<<num<<endl;
	}
    return 0;    
}
