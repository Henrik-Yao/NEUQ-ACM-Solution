#include<bits/stdc++.h>
using namespace std;
long long a[65]={0,1,3};
int main(){
	int n;
	for(int i=3;i<=64;i++){
		long long min=10000000;
		for(int j=1;j<i;j++){
			if(a[i-j]*2+pow(2,j)-1<min){
				min=a[i-j]*2+pow(2,j)-1;
			}
		}
		a[i]=min;
	}
	while(cin>>n){
		cout<<a[n]<<endl;
	}
}
