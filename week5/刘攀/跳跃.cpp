#include<bits/stdc++.h>
using namespace std;
int n, flag=0;
int maps[50010];
int a[50010];
void dfs(int x)
{
    maps[x] = 1;
    if(!a[x]){
	flag = 1; 
	return;
	}
    if(x - a[x] >= 0 && !maps[x - a[x]]) dfs(x - a[x]);
    if(x + a[x] < n && !maps[x + a[x]]) dfs(x + a[x]);
}
int main()
{
    cin>>n;
    for(int i = 0;i<n; i++)
    cin>>a[i];
    int x;
	cin>>x;
    dfs(x);
    if(flag) cout<<"True";
    else cout<<"False";
}
