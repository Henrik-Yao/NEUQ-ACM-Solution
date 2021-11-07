#include<iostream>
using namespace std;
int n;
int tuichu[501][501],way[501],use[501];
int dfs(int c) 
{
    int i;
	use[c]=1;
    if(way[c]) 
	{
	    return way[c];
    }
	for(i=1;i<=n;i++)
	{
        if(tuichu[c][i])
        {
            way[c]=way[c]+dfs(i);
        }
    }
	return way[c];
}
int main()
{
    int m,count,s1,s2,a,b,i,flag=1;
    cin>>n>>m;
    for(i=1;i<=m;i++) 
	{
        cin>>s1>>s2;
        tuichu[s1][s2]=1;
    }
    cin>>a>>b;
    way[b]=1;
    count=dfs(a);
    for(i=1;i<=n;i++) 
	{
        if(use[i]==1&&way[i]==0) 
		{
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
    	cout<<count<<" "<<"Yes"<<endl;
	}
    else
    {
        cout<<count<<" "<<"No"<<endl;
    }
	return 0;
}
