#include <bits/stdc++.h>
using namespace std;
int a[2002][2002]={0};
void shan(int i,int j)
{
	a[i][j]=0;
	if(a[i-1][j]) shan(i-1,j);
	if(a[i+1][j]) shan(i+1,j);
	if(a[i][j-1]) shan(i,j-1);
	if(a[i][j+1]) shan(i,j+1);
}
int main()
{
	
	int m,n,i,j,t=0;
	cin>>m>>n;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		cin>>a[i][j];
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i][j])
			{
				shan(i,j);
				t++;
			}
		}
	cout<<t;
	return 0;
}
