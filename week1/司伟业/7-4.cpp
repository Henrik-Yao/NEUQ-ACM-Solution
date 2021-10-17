#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int ans,n;

void dfs(int x)
{
    ans++;
    if(x==1) return;
    for(int i=1;i<x;i++)
    if(x%i==0) dfs(i);
}

int main()
{
    cin>>n;
    dfs(n);
    cout<<ans;
}
