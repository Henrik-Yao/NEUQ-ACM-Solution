#include<iostream>

using namespace std;

int sum = 0;

void count(int n) {
	for (size_t i = 1; i <=n/2; i++)
	{
		if (n % i == 0) {
			++sum;
			count(i);
		}
	}
}

int main() {
	int n; cin >> n;
	count(n);
	cout << sum+1;
}
