#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];long long int y=0;
void gb(int l,int r);
int main(){
 int n;
 cin>>n;
 for(int i = 1;i <=n;i ++)
 {
 	cin>>a[i];
 }
    gb(1,n);
    cout<<y;

}
void gb(int l,int r){
    if(l>=r) return;
    int m = (l + r)/2; 
    gb(l,m);gb(m+1,r);
    int p = l,q = m+1,j = 1;
 while(p <= m && q <= r)
 {
  if(a[p]<=a[q])
    {
    b[j++] = a[p++];
    }
  else 
    {
  b[j++] = a[q++];
  y=y+m+1-p;
    }
 }
 while(p <= m) {b[j++] = a[p++];}
 while(q <= r) { b[j++] = a[q++];}
 for(int i = l;i <= r;i ++)
 {
 	a[i] = b[i - l + 1];
 }
 
  
}
