#include <bits/stdc++.h>
using namespace std;
const int maxn=1100;
int a[maxn],b[maxn],c[maxn];
int main(){
	int T;
	cin>>T;
	int m,n;
	while(T--){
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		cin>>n;
		for(int i=m;i<m+n;i++){
			cin>>a[i];
		}
		sort(a,a+m+n);
		cout<<a[0];
		for(int i=1;i<m+n;i++){
			cout<<' '<<a[i];
		}
		cout<<endl;
		
	}
} 
