#include <iostream>
#include <math.h>
using namespace std;
int a[1000100],start,m,flag=0;
int b[1000100];
void dfs(int n)
{
    b[n]=1;
    if(a[n]==0)
    {
        flag=1;
        return;
    }
    if(n+a[n]<m&&b[n+a[n]]!=1)
    {
        dfs(n+a[n]);
    }
    if(n-a[n]>=0&&b[n-a[n]]!=1)
    {
        dfs(n-a[n]);
    }
    return ;
}
int main()
{
    int i,x;
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a[i];
    }
    cin>>start;
    dfs(start);
    if(flag==0)
        cout<<"False";
    else
        cout<<"True";
}
