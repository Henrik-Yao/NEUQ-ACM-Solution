#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,T,v,t,max=-9999,h;
cin>>n>>T;
for (int i=0;i<n;i++)
{
cin>>v>>t;
if(t>T)
h=v-(t-T);
else
h=v;
if(h>max)
max=h;
}
cout<<max;
return 0;
}