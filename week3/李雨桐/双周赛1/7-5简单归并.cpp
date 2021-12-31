#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int m,n;
       int a[105],b[105],c[205];

       cin>>m;
       for(int i=1;i<=m;i++)
        cin>>a[i];

       cin>>n;
       for(int i=1;i<=n;i++)
        cin>>b[i];

       int p=1,q=1,now=1;
       while(p<=m && q<=n)
       {
           if(a[p]<=b[q])
            c[now++]=a[p++];
           else
            c[now++]=b[q++];
       }
       while(p<=m)
       {
           c[now++]=a[p++];
       }
       while(q<=n)
       {
           c[now++]=b[q++];
       }

       for(int i=1;i<now;i++)
       {
           cout<<c[i];
           if(i!=now-1)
            cout<<' ';
       }
       cout<<endl;
   }
    return 0;
}
