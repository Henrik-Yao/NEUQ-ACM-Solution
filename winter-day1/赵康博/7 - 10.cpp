#include<bits/stdc++.h>
using namespace std;
#define N 100
stack<int> f[N];
int main() {
   int n;
   cin>>n;
   int s[n];
   for(int i = 0; i < n; i++)cin>>s[i];
   int t = 1;
   int tx;
   for(int i = 0; i < n; i++)
   {
       if(i==0)
       {
           f[t].push(s[i]);
           if(s[i]==1)tx = t;
       }
       else
       {
           int k = -1;
           int min = 1000;
           for(int j = 1; j <= t; j++)
           {
               if(f[j].top()>s[i]&&f[j].top()-s[i]<min)
               {
                   k = j;
                   min = f[j].top() - s[i];
               }
           }
           if(k==-1)
           {
               t++;
               f[t].push(s[i]);
               if(s[i]==1)tx = t;
           } else
           {
               f[k].push(s[i]);
               if(s[i]==1)tx = k;
           }
       }
   }
   int t2 = 0;
   int x[f[tx].size()];
    while (!f[tx].empty())
    {
     x[t2] = f[tx].top();
     f[tx].pop();
     t2++;
    }
    for(int i = t2 - 1; i >= 0; i--)
    {
        if(i==t2 - 1)cout<<x[i];
        else cout<<" "<<x[i];
    }
    cout<<endl<<t<<endl;
    return 0;
}
