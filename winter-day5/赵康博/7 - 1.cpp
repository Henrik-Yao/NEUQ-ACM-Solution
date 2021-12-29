#include<bits/stdc++.h>
using namespace std;
#define N 10001
int v[N];
int n;

int main()
{
   cin>>n;
   int num = 0;
   int a;
   for(int i = 0; i < n; i++){
       cin>>a;
       v[a] = 1;
   }
   for(int i = 1; i <= 10000; i++)
   {
       if(v[i]&&v[i-1])num++;
   }
   cout<<num;
   return 0;
}
