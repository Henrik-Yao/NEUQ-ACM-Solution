#include <bits/stdc++.h>
using namespace std;	
long long n,f[41];
int main(){
	cin>>n;
	f[2]=1,f[3]=2;
	for(int i=4;i<=40;i++){
		f[i]=f[i-2]+f[i-1];
	}
	while(n--){
		int m;
		cin>>m;
		cout<<f[m]<<endl;
	}
    return 0;
}




