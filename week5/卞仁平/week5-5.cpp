#include <bits/stdc++.h>
using namespace std;
int a[50005];
bool f=0;
int n;
bool is[50005];
void dfs(int s)
{
    is[s]=1;
    if(a[s]==0)
    {
        f=1;
        return ;
    }
    int r=a[s]+s;
    int l=-a[s]+s;
    if((r>=n||is[r])&&(l<0||is[l]))
    return ;
    if(r<n)
    dfs(r);
    else if(r>=0)
    dfs(l);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int start;
    cin>>start;
    dfs(start);
    if(f)
    cout<<"True";
    else cout<<"False";
    return 0;

}