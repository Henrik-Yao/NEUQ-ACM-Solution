#include <bits/stdc++.h>
using namespace std;
int a[51][51];
int n,m,k,l;
bool ju[51][51];
void dianji(int i,int j)
{
	if(ju[i][j]) return ;
	
	if(a[i][j]!=-1) return ;
	a[i][j]=0;
	int b;
	int sum=0;
	int dx[]={1,-1,0,1,-1,0,1,-1};
	int dy[]={1,-1,1,0,0,-1,-1,1};
	for(b=0;b<8;b++)
	{
		if(i+dx[b]<0||i+dx[b]>=n||j+dy[b]<0||j+dy[b]>=m) continue;
		if(ju[i+dx[b]][j+dy[b]]) sum++;
	}
	if(sum!=0) 
	{
		a[i][j]=sum;
		return ;
	}
	for(b=0;b<8;b++)
	{
		if(i+dx[b]<0||i+dx[b]>=n||j+dy[b]<0||j+dy[b]>=m) continue;
		else dianji(i+dx[b],j+dy[b]);
	}
	return ;
}
void saolei(int i,int j)
{
	if(a[i][j]!=-1) return ;
	if(ju[i][j]) 
	{
		cout<<"You lose";
		return ;
	}
	dianji(i,j);
	for(int c=0;c<n;c++)
	{
		for(int b=0;b<m;b++)
		{
			cout<<a[c][b]<<' ';
		}
		puts("");
	}
	bool judge=0;
	for(int c=0;c<n;c++)
	{
		for(int b=0;b<m;b++)
		{
			if(a[c][b]==-1&&!ju[c][b]) 
			{
				judge=1;
				break;
				break;
			}
		}
	}
	if(judge==0) 
	{
		cout<<"You win";
		puts("");
		return ;
	}
	puts("");
}
int main()
{
	memset(a,-1,sizeof(a));
	memset(ju,false,sizeof(ju));
	cin>>n>>m>>k>>l;
	while(k--)
	{
		int i,j;
		cin>>i>>j;
		ju[i][j]=1;
	}
	while(l--)
	{
		int i,j;
		cin>>i>>j;
		saolei(i,j);
	}
	return 0;
}
