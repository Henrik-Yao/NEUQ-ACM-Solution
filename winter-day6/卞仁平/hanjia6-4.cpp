#include <bits/stdc++.h>

using namespace std;
const int maxn=5e5+10;
int n,a[maxn],r[maxn];
long long ans=0;
void mergesort(int s,int t)
{
  int i,j,k,m;
  if(s==t) return;
  m=(s+t)/2; 
  mergesort(s,m); 
  mergesort(m+1,t); 
  i=s,j=m+1,k=s;
  while(i<=m&&j<=t) 
  {
    if(a[i]<=a[j])
    {
      r[k]=a[i]; i++; k++;
    }
    else
    {
      r[k]=a[j]; j++; k++;
      ans+=m-i+1;
    }
  }
  while(i<=m) { r[k]=a[i]; i++; k++; }
  while(j<=t) { r[k]=a[j]; j++; k++; }
  for(int i=s; i<=t; i++) a[i]=r[i]; 
}
int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++) scanf("%d",&a[i]);
  mergesort(1,n); 
  printf("%lld\n",ans); 
  return 0;
}
