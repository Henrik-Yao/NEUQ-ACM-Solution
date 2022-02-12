#include <bits/stdc++.h>
using namespace std;
const int maxn=110;

int r[maxn][maxn]={0};
int main()
{
	int n,e,i,sum=0,a,b,c,j,k,num ;

	while(cin>>n>>e)
	{
		memset(r, 0x3f, sizeof r);
		for(i=0;i<e;i++)
		{
			cin>>a>>b>>c;
			r[a][b]=c;	
			r[b][a]=c;
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
				if(r[i][j]>r[i][k]+r[j][k] )	r[i][j]=r[i][k]+r[j][k];
		k=0;
		for(i=0;i<n;i++)
		{
			sum=0; 
			for(j=0;j<n;j++)	
			sum+=r[i][j];
			if(!i) num=sum;
			else if(num>sum)
			{
				num=sum;
				k=i;
			}
		}
		cout<<k<<endl;
	}
	return 0;
 } 
