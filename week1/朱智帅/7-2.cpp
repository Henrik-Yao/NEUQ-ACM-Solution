#include<iostream>
#include<iomanip>
#include<set>
#include<cmath>
using namespace std;
int dpf[1000001], dpe[1000001], number[100001];
int main()
{
	int n, i, j, cnt = 0;
	cin >> n;
	set<int> s;
	for (i = 0; i < n; i++)
	{
		cin >> number[i];
		if (s.find(number[i]) == s.end()) cnt++;
		s.insert(number[i]);
		dpf[i] = cnt;
	}
	s.clear();
	cnt = 0;
	for (i = n - 2; i > -1; i--)
	{
		if (s.find(number[i + 1]) == s.end()) cnt++;
		s.insert(number[i + 1]);
		dpe[i] = cnt;
	}
	dpe[n - 1] = 0;
	int max = dpf[0] + dpe[0];
	for (i = 1; i < n; i++)
	{
		if (dpf[i] + dpe[i] > max) max = dpf[i] + dpe[i];
	}
	cout << max;
	return 0;
}