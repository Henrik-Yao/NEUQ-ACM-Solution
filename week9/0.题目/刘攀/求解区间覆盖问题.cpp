#include<bits/stdc++.h>
using namespace std;
int a[10000];
int b[10000];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i]-1;
	}
	sort(b,b+n-1,greater<int>());
	int len=a[n-1]-a[0]+1;
	int j=0;
	for(int i=1;i<m&&i<n;i++){
		len-=b[j++];
	}
	cout<<len<<endl;
}
