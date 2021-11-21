#include <bits/stdc++.h>
using namespace std;
int prime(int n){
	bool p=1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			p=0;
			break;
		}
	}
	return p;
}	
int main(){
	int a,b;
	while(cin>>a>>b){
		int s[10001],n=0;
		for(int i=a;i<=b;i++){
			if(prime(i)){
				s[n]=i;
				n++;
			} 
		}
		for(int j=0;j<n-1;j++) cout<<s[j]<<" ";
		if(n>0) cout<<s[n-1]<<endl;
	}
    return 0;
}




