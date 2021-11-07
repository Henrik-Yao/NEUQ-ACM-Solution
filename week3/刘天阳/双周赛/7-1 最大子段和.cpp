#include <iostream>

using namespace std;

int main (){
	int n;
	int ans = 0, sum = 0, a;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if(sum > 0) sum += a;
		else sum = a;
		ans = max(ans, sum);
	}
 	cout << ans;
	
	
	return 0;
}
