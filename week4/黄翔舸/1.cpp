#include<iostream>
#include<cstring>
using namespace std;
int main()
{

	int ss[10001];
	bool bj[10001];
	int a, b;
	while (cin >> a >> b)
	{
		int e = 0;
		memset(ss, 0, sizeof(ss));
		memset(bj, false, sizeof(bj));
		for (int i = 2; i <= b; i++)
		{
			if (!bj[i])
			{
				ss[e] = i;
				e++;
			}
			for (int j = 0; j < e && i * ss[j] <= b; j++)
			{

				bj[i * ss[j]] = true;

				if (i % ss[j] == 0)
					break;
			}



		}
		int n = 0;
		for (int i = 0; i < e; i++)
		{
			if (ss[i] >= a && n == 0)
			{
				cout << ss[i];
				n++;
			}
			else if (ss[i] >= a)
				cout << " " << ss[i];
		}
		cout << endl;
	}



	return 0;
}