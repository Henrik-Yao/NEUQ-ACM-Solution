#include <iostream>

using namespace std;

const int T = 1e6+5;
const int B = 1e5+5;

bool Bvis[B];
int Ifrom_s[T], Ifrom_e[T], Idate[T];

int main (){
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> Idate[i];
	
	for (int i = 1; i <= n; i++) {
		if(!Bvis[Idate[i]]) {
			Bvis[Idate[i]] = 1;
			Ifrom_s[i] = Ifrom_s[i-1] + 1;
		}
		else Ifrom_s[i] = Ifrom_s[i-1];
	}
	
	for (int i = 0; i <= B - 3; i++) Bvis[i] = 0;
	
	for (int i = n; i >= 1; i--) {
		if(!Bvis[Idate[i]]){
			Bvis[Idate[i]] = 1;
			Ifrom_e[i] = Ifrom_e[i+1] + 1;
		}
		else Ifrom_e[i] = Ifrom_e[i+1];
	}
	
	int ans = Ifrom_s[1] + Ifrom_s[2];
	
	for (int i = 1; i < n; i++) ans = max(ans, Ifrom_s[i] + Ifrom_e[i+1]);
/*	
	for (int i = 1; i <= n; i++) cout << Ifrom_s[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; i++) cout << Ifrom_e[i] << " ";
	cout << endl;
	测试两个数组是否正常 
*/
	cout << ans;
	
	
	
	return 0;
}
