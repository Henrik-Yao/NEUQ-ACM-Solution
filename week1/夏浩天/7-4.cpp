#include<iostream>
#include<algorithm>
using namespace std;
int ftg(int n, int sum)
{
	if (n == 1)sum=sum+1;
	else
	{
		for (int i = n / 2;i > 0;i--)
		{
			if (n % i == 0&&i!=1)
			{
				sum=ftg(i, sum)+1;
			}
			else if (n % i == 0 && i == 1)
			{
				sum++;
			}
		}
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int b=ftg(n, sum);
	if(n>1)
	cout << b+1;
	else
		cout<<"1";
}