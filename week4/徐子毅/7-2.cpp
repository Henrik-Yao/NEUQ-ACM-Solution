#include <iostream>
using namespace std;
int step(int n){
	if(n==1) return 0;
	else if(n==2) return 1;
	else if(n==3) return 2;
	else{
		return step(n-1)+step(n-2);
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int nu;
		cin >> nu;
		cout << step(nu);
	}
	return 0;
}