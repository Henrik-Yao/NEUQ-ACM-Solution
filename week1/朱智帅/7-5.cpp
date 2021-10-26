#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<string>
using namespace std;
struct people
{
	int dir;
	char name[100];
};
people P[100001];
int main()
{
	int n, m, i, D, N;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> P[i].dir >> P[i].name;
	}
	int firstp = P[0].dir;
	for (i = 0; i < m; i++)
	{
		cin >> D >> N;
		if (D == P[firstp].dir) firstp = (firstp - N + n) % n;
		else firstp = (firstp + N) % n;
	}
	cout << P[firstp].name;
	return 0;
}