#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001]; 
void gb(int l,int r);
int main(){
 int n;
 cin>>n;
 for(int i = 1;i <= n;i ++){
 	cin>>a[i];
 }
 
 gb(1,n);
 for(int i = 1;i <= n;i ++){
 	cout<<a[i]<<" ";
 }

}
void gb(int l,int r){if(l == r)return;
	
 int m = (l + r)/2; 
 gb(l,m);gb(m+1,r);
 int p = l,q = m+1,j = 0;
 while(p <= m && q <= r){
  if(a[p] < a[q])b[++j] = a[p],p++;
  else b[++j] = a[q],q++;
 }
 while(p <= m&&q>=r) {b[++j] = a[p];p ++;
 }
 while(q <= r&&p>=m){ b[++j] = a[q];q ++;
 }
 for(int i = l;i <= r;i ++){
 	a[i] = b[i - l + 1];
 }
 
  
}
