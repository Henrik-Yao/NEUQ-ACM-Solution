#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,c;
	while(cin>>n>>c)//多组数据 
	{
		int ma=0,m[401][1501],w[401],v[401];//max不能做变量名 
		for(int i=0;i<=c;i++) m[0][i]=0;
		for(int i=1;i<=n;i++) cin>>w[i];
		for(int i=1;i<=n;i++) cin>>v[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=c;j++)
			{
				if(j<w[i]) m[i][j]=m[i-1][j];
				else m[i][j]=max(m[i-1][j-w[i]]+v[i],m[i-1][j]);
				if(m[i][j]>ma) ma=m[i][j];
			}
		}
		cout<<ma<<endl;//不需要两个换行 
	}
	return 0;
}
