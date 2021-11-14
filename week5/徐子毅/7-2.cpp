#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int n){
	if(n<=1) return false;
	else{
		for(int i=2;i<=sqrt(n);i++){
			if(n%i==0) return false;
		}
		return true;
	}
}
int main(){
	int N,n;
	cin >> N;
	for(int abc=1;abc<=N;abc++){
		int sum=0;
		cin >> n;
		if(isprime(n)){sum=1;}
		else if(n%2==0){sum=2;}
		else if(isprime(n-2)){sum=2;}
		else {sum=3;}
		cout << sum << endl;
	}
}