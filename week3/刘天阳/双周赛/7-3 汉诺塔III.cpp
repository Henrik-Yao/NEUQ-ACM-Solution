#include <iostream>

using namespace std;

int main (){
	
	int n;
	long long ans;
	
	ans = 2;
	
	//Èý²½  ans[i]  = ans[i-1] + 1 + ans[i-1] + 1 + ans[i-1];
	//ans[i] = 3 * ans[i-1] + 2;
	
	while(cin >> n) {
		
		for (int i = 2; i <= n; i++)	ans = 3*ans + 2;
 	
 		cout << ans << endl;
 	
 		ans = 2;
	}
	
	
	
	return 0;
}
