#include<bits/stdc++.h>
using namespace std;
int sum=0;
int m,n;
bool tu[2001][2001];
void ping(int i,int j)
{
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	for(int k=0;k<=3;k++)
	{
		if(dx[k]+i>=0&&dy[k]+j>=0&&dx[k]+i<m&&dy[k]+j<n&&tu[dx[k]+i][dy[k]+j])
		{
			tu[dx[k]+i][dy[k]+j]=0;
			ping(dx[k]+i,dy[k]+j);
		}
	}
}
void shan(int i,int j)
{
	if(tu[i][j]) 
	{
		sum++;
		ping(i,j);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++) cin>>tu[i][j];
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++) shan(i,j);
	cout<<sum;
	return 0;
}