#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[j] - a[i] == 1 || a[j] - a[i] == -1)++sum;
	cout << sum;
}

