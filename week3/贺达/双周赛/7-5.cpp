#include<bits/stdc++.h>
using namespace std;

int a[110];
int b[110];
int c[220];
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int x,y;
        x=y=0;
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>a[j];
        }
        int n;
        cin>>n;
        for(int k=0;k<n;k++)
        {
            cin>>b[k];
        }
        for(int p=0;p<m+n;p++)
        {
            if(x>=m)
            {
                c[p]=b[y];
                y++;
            }
            else if(y>=n)
            {
                c[p]=a[x];
                x++;
            }
            else if(a[x]>b[y])
            {
                c[p]=b[y];
                y++;
            }
            else if(a[x]<=b[y])
            {
                c[p]=a[x];
                x++;
            }

            if(p==m+n-1)
            {
                cout<<c[p];
            }
            else
            {
                cout<<c[p]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
