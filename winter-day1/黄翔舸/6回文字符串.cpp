#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string c1;
	cin >> c1;
	long long int uq = 0;
	int flag = 0;
	for (long long int yq = c1.length() - 1; yq >= 0; yq--)
	{
		if (c1[yq] == c1[uq])
		{

		}
		else
		{
			flag++;
			break;
		}
		uq++;
	}
	if (flag)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return 0;
}