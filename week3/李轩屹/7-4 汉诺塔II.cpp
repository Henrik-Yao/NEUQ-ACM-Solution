#include<bits/stdc++.h>  
using namespace std;
double f[65],a[65];
void k(int n){
	f[1]=1;
	for(int i=2;i<=64;i++) f[i]=2*f[i-1]+1;
}
int main(){
	int n;
	k(n);
	while(cin>>n){
		for(int i=1;i<=64;i++) a[i]=1e5+10;
	    for(int i=1;i<=n;i++){
		    for(int j=0;j<i;j++){
		     	a[i]=min(2*a[j]+f[i-j],a[i]);
	     	}
	    }
	cout<<a[n]<<endl;
	}
	return 0;
}
