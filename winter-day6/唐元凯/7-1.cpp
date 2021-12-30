#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int>a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int pos = 1;
		for (int i = 1; i < n; i++)
		{
			int temp = a[pos++];
			int j;
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
			for (auto &c : a) {
				cout << c;
				if (&c != &a[n - 1])cout << " ";
			}
			cout << endl;
		}
	}
}