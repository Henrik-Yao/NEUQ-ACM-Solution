#include <bits/stdc++.h>
using namespace std;
int a[1000],s[1000];
int cmp(int a,int b){
  return a>b;
}
int main(){
	ios::sync_with_stdio(false);
    int n,m,len,sum;
    cin>>n>>m;
    for(int i=0;i<=n-1;i++) cin>>a[i];
    sort(a,a+n);
    len=a[n-1]-a[0]+1;
    for(int i=0;i<n-1;i++) s[i]=a[i+1]-a[i]-1;
    sort(s,s+n-1,cmp);
    sum=len;
    for(int i=0;i<m-1;i++) sum-=s[i];
    cout<<sum;
}
 

