#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
 {
		uint64_t A, B, C, i, sum, flag;
		cin >> A >> B >> C;
		sum = A;
		for (i = 1; i < B; i++)
		{
			sum = ((sum % C) * (A % C)) % C;
		}
		cout << sum << endl;
	}
	return 0;
}