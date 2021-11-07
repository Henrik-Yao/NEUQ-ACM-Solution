#include <iostream>
using namespace std;
long long ans[55];
int main (){
	ans[1] = 1, ans[2] = 1;
	int n;
	cin >> n;
	for (int i = 3; i <= 40; i++) ans[i] = ans[i-1] + ans[i-2];
	ans[1] = 0;
	while(n--) { 
		int k;
		cin >> k;
		cout << ans[k];
		if(n) cout << endl;
	}
	
	return 0;
}
