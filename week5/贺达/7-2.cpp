#include<iostream>
#include<cmath>
using namespace std;

bool su(int n)
{
	int i;
	for(i=2; i<=sqrt(n); i++) {
		if(n%i==0)return false;
	}
	return true;
}

int main() {
	int n,t;
	cin>>n;
	while(n--) {
		cin>>t;
		if(t%2==0) {
			cout<<2<<endl;
		} else if(su(t)) {
			cout<<1<<endl;
		} else {
			if(su(t-2)) {
				cout<<2<<endl;
			} else cout<<3<<endl;
		}
	}
	return 0;
}


