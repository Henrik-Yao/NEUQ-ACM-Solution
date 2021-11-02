#include <iostream>

using namespace std;

long long c;
long long QPow(long long a, long long b) {
	long long ans = 1, base = a;
	while(b) {
		if(b & 1) ans *= base;
		
		b>>=1;
		
		base *= base;
		
		base %= c;
		ans %= c;
	}
	return ans;
}

int main (){
	
	int n;
	long long a, b;
	
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;
		cout << QPow(a, b) << endl;
	}
	
	
	return 0;
}
