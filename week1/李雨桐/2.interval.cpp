#include <bits/stdc++.h>

const int N=1e6+5;

using namespace std;

int n;
int a[N],b1[N],b2[N],c1[N],c2[N];

int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
    cin>>a[i];

   for(int i=1;i<=n;i++)
   {
       if(c1[a[i]]==0)
           {
                b1[i]=b1[i-1]+1;
                c1[a[i]] = 1;
           }
       else
            b1[i]=b1[i-1];

   }

   for(int i=n;i>0;i--)
   {
       if(c2[a[i]]==0)
           {
                b2[i]=b2[i+1]+1;
                c2[a[i]] = 1;
           }
       else
            b2[i]=b2[i+1];
   }

   int sum,maxi=0;

   for(int i=1;i<n;i++)
   {
       sum = b1[i]+b2[i+1];
       if(sum>maxi)
        maxi = sum;
   }

   cout<<maxi<<endl;

    return 0;
}
