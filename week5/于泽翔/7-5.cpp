#include <bits/stdc++.h>
using namespace std;
int m[50010], n, st;
bool vis[50010];

int search(int a)
{
    vis[a]=1;
    if(vis[a-m[a]]==0)
        search(a-m[a]);
    if(vis[a+m[a]]==0)
        search(a+m[a]);
}
int main(void)
{
    memset(vis, 0, 50010);
    
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>m[i];
    cin>>st;
    
    search(st);
    
    for(int i=0; i<n; i++)
        if(m[i]==0&&vis[i]==1)
        {
            cout<<"True";
            return 0;
        }
        cout<<"False";
	
	return 0;
}