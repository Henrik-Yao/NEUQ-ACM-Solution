#include<bits/stdc++.h>
using namespace std;
long long f(int n);
int main(){
	int n;
	while(~scanf("%d",&n)){
	cout<<f(n)<<endl;
	}
}
long long f(int n){
	if(n==1)return 2;
	else return 3*f(n-1)+2;
}
