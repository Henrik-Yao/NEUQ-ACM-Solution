#include <bits/stdc++.h>
using namespace std;
struct ty
{
	char sex;
	int f=-1;
	int m=-1;
}a[100010];
int n,k;
bool dfs(int id1,int id2,int cnt)
{
	if(id1<0||id2<0)
	{
		return 1;
	}
	if((a[id1].f>=0&&a[id1].f==a[id2].f)||(a[id1].m>=0&&a[id1].m==a[id2].m))
	{
		return 0;
	}
	cnt=cnt+1;
	if(cnt==5)
	{
		return 1;
	}
	  if(dfs(a[id1].f,a[id2].f,cnt)==0||dfs(a[id1].f,a[id2].m,cnt)==0||
	  dfs(a[id1].m,a[id2].f,cnt)==0||dfs(a[id1].m,a[id2].m,cnt)==0)
	  return 0;
	  else return 1;
}
int main()
{
	cin>>n;
	while(n--)
	{
		int id;
		cin>>id;
		cin>>a[id].sex>>a[id].f>>a[id].m;
		a[a[id].f].sex='M';
		a[a[id].m].sex='F';
	}
	cin>>k;
	while(k--)
	{
		int id1,id2;
		cin>>id1>>id2;
		if(a[id1].sex==a[id2].sex)
		{
			cout<<"Never Mind"<<endl;
		}
		else
		{
			if(dfs(id1,id2,1)==0)
			{
				cout<<"No"<<endl;
			}
			else
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}

