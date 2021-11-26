#include<iostream>
using namespace std;
int testnumber[10005], LST[1005];
int main()
{
	int T, n, i, j, max;
	cin >> T;
	while (T--)
	{
		cin >> n;
		max = 1;
		for (i = 0; i < n; i++)
		{
			cin >> testnumber[i];
			LST[i] = 1;
		}
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				if (testnumber[i] > testnumber[j])
				{
					if (LST[j] + 1 > LST[i]) LST[i] = LST[j] + 1;
				}
			}
			if (LST[i] > max) max = LST[i];
		}
		cout << max <<endl;
        if(T) cout<<endl;
	}
	return 0;
}