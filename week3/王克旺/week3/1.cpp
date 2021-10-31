#include<bits/stdc++.h>
using namespace std;
int m,n,k,s,d,flag=0;
bool safe[101];
int road[101][101],se[101]={0};
void dfs(int c)
{
    if(c==d) 
    {
        flag=1;      
        return;
    }
    for(int i=0;i<m;i++)
    {
        if(safe[i]==0||se[i]==1||road[c][i]==0) 
		{
		    continue;
        }
		se[i]=1;
        dfs(i);
        se[i]=0;
    }
    return;
}
int main()
{
    int i;
	cin>>m>>n>>k;
    for(i=0;i<n;i++)
    {
        int city;
        cin>>city;
        safe[city]=1;
    }
    for(i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        road[a][b]=1;
        road[b][a]=1;
    }
    cin>>s>>d;
	dfs(s);
    if(safe[d]==0)
    {
        cout<<"The city "<<d<<" is not safe!";
    }
	else
	{	
        if(flag==0)
        {
            cout<<"The city "<<d<<" can not arrive safely!";
        }
	    else
        {
	        cout<<"The city "<<d<<" can arrive safely!";
        }
    }
	return 0;
}
