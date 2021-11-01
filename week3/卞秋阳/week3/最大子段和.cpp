#include<bits/stdc++.h>
using namespace std;
int n,a[100001],t[100001]; 
int find(int l,int r);
int main(){
 cin>>n;
 for(int i = 1;i <= n;i ++)
 cin>>a[i];
 int d=find(1,n);
 if(d<0) d=0;
 cout<<d<<endl;
}

int find(int l,int r){
 if(l == r){
 return a[l];}
 int m = (l + r)/2;
 int L = find(l,m),R = find(m+1,r);
 int suml = 0,sumr = 0,b= -1e9,c = -1e9;
 for(int i = m;i >= l;i --){
  suml += a[i];
  b = max(b,suml);
 }
 for(int i = m + 1;i <= r;i ++){
  sumr += a[i];
  c = max(c,sumr);
 }
 return max(max(L,R),max(b + max(0,c),max(0,b)+c));
}
