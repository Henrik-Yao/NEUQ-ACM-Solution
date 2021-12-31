#include<bits/stdc++.h>
using namespace std;
int isprime(int n){
	int flag = 1;
	if(n==1)
	return 1;
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i==0)
		{
			flag = 0;
			break;
		}
	}
	if(flag == 1)
	return 1;
	else
	return 0;
}
int main(){

	int n,a;
	cin>>n;
	while(n--){
		cin>>a;
		if(a%2==0&&a!=2)
		cout<<2<<endl;
		else{
			if(isprime(a))
			cout<<1<<endl;
		
		else{
			if(isprime(a-2))
			cout<<2<<endl;
			else
			cout<<3<<endl;
		}
	}
}
}
