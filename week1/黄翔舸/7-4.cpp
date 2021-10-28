#include<iostream>
using namespace std;
int main()
{
	int sum(int n);
	int n;
	cin >> n;
	cout << sum(n);



	return  0;
}
int sum(int n) {

	if (n == 1)
	{
		return 1;
	}
	int i = 1;
	int p = 1;
	while (i < n)
	{
		if (n % i == 0)
			p = p + sum(i);
		i++;
	}
	return p;
}