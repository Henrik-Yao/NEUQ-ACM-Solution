#include<bits/stdc++.h>
using namespace std;
//long long res = 0;

long long res[36];

int main() {
	int n;
	res[0] = 1;
	for(int i = 1; i <= 35; i++){
//		res[i] = pow(3, i); pow¹ý²»È¥£¡£¡£¡£¡ 
		res[i] = res[i-1] * 3;
	}
	while(cin >> n){
//		res = pow(3, n) - 1;
		cout << res[n]-1 << endl;
	}
}
