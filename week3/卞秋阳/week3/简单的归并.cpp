#include<bits/stdc++.h>
using namespace std;
int main(){
int n;int e;
cin>>n;
int a[110];
int b[110];
int c[1000];
int t;
for(int j=1;j<=n;j++){
cin>>t;
for(int i=1;i<=t;i++){
	cin>>e;
	a[i]=e;
}
int k;cin>>k;
for(int i=1;i<=k;i++){
	cin>>e;
	b[i]=e;
}
for(int i=1;i<=t;i++){
	c[i]=a[i];
}
for(int i=t+1;i<=t+1+k+1;i++){
	c[i]=b[i-t];
}
sort(c+1,c+1+k+t);
for(int i=1;i<k+t;i++){cout<<c[i]<<" ";
}
cout<<c[k+t]<<endl;

} }
