#include <bits/stdc++.h>
using namespace std;

struct per{
int d;
string name;
};


int main()
{

   int n,m;
   cin>>n>>m;

    per a[n+5];

   for(int i=1;i<=n;i++)
   {
       cin>>a[i].d>>a[i].name;

   }

   int j=1,di,pace;

   for(int i=1;i<=m;i++)
   {
       cin>>di>>pace;

       if(di==0)
       {
           if(a[j].d==0)
           {
                j = j-pace;
            if(j<=0)
                j = j+n;
           }

           else if(a[j].d==1)
           {
               j = j+pace;
               if(j>n)
                j = j-n;
           }
       }
       else if(di==1)
       {
           if(a[j].d==0)
           {
                j = j+pace;
             if(j>n)
                j = j-n;
           }

           else if(a[j].d==1)
           {
               j = j-pace;
               if(j<=0)
                j = j+n;
           }
       }
   }

   cout<<a[j].name;

    return 0;
}
