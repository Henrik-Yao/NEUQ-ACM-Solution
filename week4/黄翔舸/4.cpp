#include<iostream>
using namespace std;
typedef long long ll;
ll ksm(ll a, ll b, ll c);
int main()
{

	long long int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long int x, y, z;
		cin >> x >> y >> z;
		cout << ksm(x, y, z) << endl;


	}



	return 0;
}
ll ksm(ll a, ll b, ll c)
{
	long long int s = 1;
	while (b > 1)
	{
		if (b % 2 == 1)
		{
			s = s * a;
			s = s % c;
			b = b - 1;

		}
		else
		{
			a = a * a;
			a = a % c;
			b = b / 2;
		}

	}



	return(s * a) % c;








}