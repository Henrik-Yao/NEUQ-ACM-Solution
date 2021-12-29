#include<bits/stdc++.h>
using namespace std;
#define N 2000010
int main()
{
   int n;
   cin>>n;
   int f[N];
   for(int i = 0; i < 2*n; i++){
      cin>>f[i];
   }
   sort(f,f+2*n);
   cout<<f[(2*n-1)/2];
   return 0;
}
