#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

bool prime[10001];

void isprime() {
	for (size_t i = 1; i <= 10000; i++)
	{
		for (size_t j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0) {
				prime[i] = 0; break;
			}
		}
	}
}

int main() {
	memset(prime, 1, sizeof(prime));
	isprime();
	int a, b;
	while (cin>>a>>b)
	{
		int i;
		for ( i = a; i <= b; i++)
		{
			if (prime[i]) {
				cout << i;
				++ i;
				break;
			}
		}
		for ( ; i <= b; i++)
		{
			if (prime[i])cout << " " << i;
		}
		cout << '\n';
	}
}