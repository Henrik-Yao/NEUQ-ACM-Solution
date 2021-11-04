#include<iostream>
using namespace std;
int main()
{
    int n,m,way[41];
    way[1]=0;
    way[2]=1;
    way[3]=2;
    for(int i=4;i<=40;i++)
    {
        way[i]=way[i-1]+way[i-2];
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        cout<<way[m]<<"\n";
    }
    return 0;
}