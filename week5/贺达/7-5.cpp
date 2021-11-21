#include<bits/stdc++.h>
using namespace std;
int  flag;
int vis[100000], a[100000];

void dfs(int x,int n)
{
    vis[x] = 1;
    
    if(!a[x]) 
    {
	flag = 1; 
	return;
	}
    if(x - a[x] >= 1 && !vis[x - a[x]])
    {
        dfs(x - a[x],n);
    } 
    if(x + a[x] <= n && !vis[x + a[x]])
    {
        dfs(x + a[x],n);
    }
	 
}

int main()
{
    int n,t;
    cin>>n;
    for(int i = 1; i <= n; ++i)
    {
        cin>>a[i];
    
    }
    cin>>t;
    dfs(t+1,n);
    if(flag)
    {
        cout<<"True";
    }
    else
    {
         cout<<"False";
    }
       
    return 0;
}
