#include<iostream>

using namespace std;

long long strangehanoi(int n) {
	if (n == 1) {
		return 2;
	}
	else {
		return 3 * strangehanoi(n - 1) + 2;
	}
}

int main()
{
	int n;
	while (cin >> n) {
		cout << strangehanoi(n) << endl;
	}
}
