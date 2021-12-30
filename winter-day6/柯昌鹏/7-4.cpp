#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn],r[maxn];
long long ans=0;
void mergesort(int s,int t)
{
  int i,j,k,m;
  if(s==t) return;
  m=(s+t)/2; //取中点
  mergesort(s,m); //递归左区间
  mergesort(m+1,t); //递归右区间
  i=s,j=m+1,k=s;
  while(i<=m&&j<=t) //二路归并（升序）过程
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
  } //将序列中剩余的元素接入r数组
  while(i<=m) { r[k]=a[i]; i++; k++; }
  while(j<=t) { r[k]=a[j]; j++; k++; }
  for(int i=s; i<=t; i++) a[i]=r[i]; //数组赋回
}
int main()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++) scanf("%d",&a[i]);
  mergesort(1,n); //归并求解逆序对
  printf("%lld\n",ans); //别忘了long long
  return 0;
}