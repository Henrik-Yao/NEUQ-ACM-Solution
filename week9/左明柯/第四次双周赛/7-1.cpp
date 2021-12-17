#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m,l;
int a[100],b[100];
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
l=a[n-1]-a[0]+1;
for(int i=0;i<n-1;i++){
	b[i]=a[i+1]-a[i]-1;
}
sort(b,b+n-1);
for(int i=n-2;i>=n-m;i--){
	l-=b[i];
}
cout<<l;
return 0;

}
