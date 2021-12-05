#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int d[n];
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            d[i]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i])
                {
                   d[i]=max(d[i],d[j]+1);
                }
            }
        }
        sort(d,d+n);
        cout<<d[n-1];
        if(t!=0)
        {
            cout<<endl;
            cout<<endl;
        }
    }
    return 0;
}
