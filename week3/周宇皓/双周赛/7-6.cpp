#include<bits/stdc++.h>
using namespace std;
char a[30];
void p_1(char a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	cout << endl;
}
void aa(char a[], int m, int n) {
	if (m == n) {
		p_1(a, n);
	}
	else {
		for (int i = m; i < n; i++) {
			swap(a[m], a[i]);
			aa(a, m + 1, n);
			swap(a[i], a[m]);
		}
	}
}
int main() {

	cin>>a;
		int i;
		for (i = 0; i < strlen(a); i++) {
			a[i] = 'a' + i;
		}
		aa(a, 0, strlen(a));
		cout << endl;
	
	return 0;
}

