#include <iostream>
#include <string>

using namespace std;

int ans[1009];
char b[1009];

void Fin(char c, int l, int n) {
	b[l] = c;
//	cout << "!ss";
	if(!n) {
		for (int i = 1; i <= l; i++) cout << b[i];
		cout << endl;
	}
	else {
		for (int i = 'a'; i <= 'z'; i++) {
			if(ans[i]) {
				ans[i]--;
				Fin(char(i), l+1, n-1);
				ans[i]++;
			}
		}
	}
	
	
}

int main(){
	string a;
	
	cin >> a;
	
	for (int i = 0; i < a.size(); i++)	ans[a[i]]++;
	
//	for (int i = 'a'; i <= 'z'; i++) cout << ans[i];
	
	for (int i = 'a'; i <= 'z'; i++) {
//		cout << "!!";
			if(ans[i]) {
				ans[i]--;
				Fin(char(i), 1, a.size()-1);
				ans[i]++;
			}
		}
	
	return 0;
}
