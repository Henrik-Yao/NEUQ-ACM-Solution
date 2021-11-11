#include<bits/stdc++.h> 
using namespace std;
const int M=50000;
int a[M];
bool judge[M];
int n,i,start,flag,k=0;
void dfs(int start)
{
	if(k==1||judge[start]==1) return;
	judge[start]=1;
	if(a[start]==0)
	{
		k=1;return;
	}
	if(start+a[start]<n&&start+a[start]>=0&&judge[start+a[start]]==0) dfs(start+a[start]);
	if(start-a[start]<n&&start-a[start]>=0&&judge[start-a[start]]==0) dfs(start-a[start]);
}
int main()
{
	memset(a,0,sizeof(a));
	memset(judge,0,sizeof(judge));
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>start;
	dfs(start);
	if(k==1)
	{
		cout<<"True"; 
	}
	else
	{
		cout<<"False";
	}
} 

