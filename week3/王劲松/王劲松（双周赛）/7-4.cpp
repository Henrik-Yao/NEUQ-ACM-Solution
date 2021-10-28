#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n,s;
	int a[65];
	a[0]=0,a[1]=1,a[2]=3,a[3]=5;
	for(i=4;i<=64;i++){
		int m=66666666;
		for(s=1;s<i;s++){
			if(2*a[s]+pow(2,i-s)-1<m){
				m=2*a[s]+pow(2,i-s)-1;
			}
		}
		a[i]=m;
	}
	while(~scanf("%d",&n)){
		cout<<a[n]<<endl;
	}
	return 0;
}
