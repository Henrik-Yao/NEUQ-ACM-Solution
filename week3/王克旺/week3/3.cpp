#include<iostream>
using namespace std;
int n,m,k,l,num,x1,y1;
int lei[50][50]={-1},flag[50][50],judge[50][50];
int x[8]={0,0,1,1,1,-1,-1,-1};
int y[8]={-1,1,-1,0,1,-1,0,1};
int cnt(int a,int b)
{
	int i,count=0;
	for(i=0;i<8;i++)
	{
		x1=a+x[i];
		y1=b+y[i];
		if(x1<0||x1>=n||y1<0||y1>=m)
		{
			continue;
		} 
		if(flag[x1][y1]==1) 
		{
			count++;
		}
	}
	return count;
}
int f(int a,int b)
{
	int i,t=0;
	for(i=0;i<8;i++)
	{
		x1=a+x[i];
		y1=b+y[i];
		if(x1<0||x1>=n||y1<0||y1>=m)
		{
			continue;
		}
		if(flag[x1][y1]==1)
		{
			t=1;
		}
	}
	if(t==1)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}		
void saolei(int a,int b)
{
	int i;
	judge[a][b]=1;
	num++;
	if(f(a,b)==1)
	{
		lei[a][b]=cnt(a,b);
		for(i=0;i<8;i++)
		{
			x1=a+x[i];
			y1=b+y[i];
			if(x1<0||x1>=n||y1<0||y1>=m||judge[x1][y1]) 
			{
				continue;
			} 
			saolei(x1,y1);
		}
		return; 
	}
	else
	{
		lei[a][b]=cnt(a,b);
		return;
	}	
}
int main()
{
	int i,j;
	cin>>n>>m>>k>>l;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			lei[i][j]=-1;	
		}
	}			
	for(i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		flag[a][b]=1;
	}
	while(l--)
	{
		int a,b;
		cin>>a>>b;
		if(flag[a][b]==1)
		{
			cout<<"You lose";
			break;
		}
		if(lei[a][b]!=-1) 
		{
			continue;
		}
		if(lei[a][b]==-1)
		{ 
			saolei(a,b);
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					cout<<lei[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		if(num==n*m-k)
		{
			cout<<"You win";
			return 0;
		}
		cout<<endl;
	}
	return 0;
}
