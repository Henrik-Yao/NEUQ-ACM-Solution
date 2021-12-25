#include <iostream>
#include <algorithm>
using namespace std;
int a[1000005];
int s[1000005];
int cmp(int a,int b)
{
  return a>b;
}
int main()
{
    int n,m;
    int l=0;
    int sum=0;cin>>n>>m;
     for(int i=0;i<=n-1;i++)
     {
      cin>>a[i];
     }
     sort(a,a+n);
     l=a[n-1]-a[0]+1;
     for(int i=0;i<n-1;i++)
     {
      s[i]=a[i+1]-a[i]-1;
     }
     sort(s,s+n-1,cmp);
     sum=l;
     for(int i=0;i<m-1;i++)
     {
      sum=sum-s[i];
     }
    cout << sum << endl;
}
