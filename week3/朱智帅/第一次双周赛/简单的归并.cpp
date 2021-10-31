#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	int T, allnumber[100001], i;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m;
		for (i = 0; i < m; i++)
			cin >> allnumber[i];
		cin >> n;
		for (; i < n+m; i++)
			cin >> allnumber[i];
		sort(allnumber, allnumber + m + n);
		for (i = 0; i < m + n-1; i++)
			cout << allnumber[i] << " ";
        cout<<allnumber[i]<<endl;
	}
	return 0;
}