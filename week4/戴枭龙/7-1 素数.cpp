#include <bits/stdc++.h>
using namespace std;
int flag;
int prime;

int main() {
	int a, b;
	while (cin >> a >> b) {
		flag=1;
		for (int i = a; i <= b; i++) {
			int j, prime = 1;
			for (j = 2; j * j <= i; j++)
				if (i % j == 0)
					prime = 0;
			if (flag) {
				if (prime) {
					cout << i ;
					flag = 0;
				}
			} else if (prime) {
				cout << " " << i ;
			}
		}
		cout << endl;
	}

	return 0;
}
