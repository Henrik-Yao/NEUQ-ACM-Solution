#include <iostream>

using namespace std;

unsigned long long ans1[80], ans2[80]; //ans1 为三根柱子 ans2 为两根柱子 

int main (){
	
	for (int i = 1; i <= 64; i++) {
		
		long long ans = 1;
		for (int j = 1; j <= i; j++) ans *= 2;
		ans1[i] = ans - 1;
		
	}
	
	ans2[1] = 1;
	
	for (int i = 2; i <= 64; i++) {
		ans2[i] = 1 + 2*ans1[i-1];
		for (int j = 1; j < i; j++) {
			ans2[i] = min(ans2[i], 2*ans2[j] + 2*ans1[i-1-j] + 1);
		}
	}
	
	int n;
	
	while(cin >> n) cout << ans2[n] << endl;
	
	
	return 0;
}
