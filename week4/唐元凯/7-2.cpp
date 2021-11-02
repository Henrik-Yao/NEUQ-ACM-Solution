#include<iostream>

using namespace std;

int fibo(int n) {
	if (n == 1)return 0;
	if (n == 2)return 1;
	if (n == 3)return 2;
	int result, l_result, ll_result;
	ll_result = 1, l_result = 2;
	for (size_t i = 4; i <=n; i++)
	{
		result = ll_result + l_result;
		ll_result = l_result;
		l_result = result;
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	while (N--) {
		int M;
		cin >> M;
		cout<<fibo(M)<<'\n';
	}
}