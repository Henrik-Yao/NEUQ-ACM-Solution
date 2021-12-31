#include<iostream>
#include<set>
using namespace std;
int n;
int Age[52] = { 0 };
set<int>S;
int main()
{
	cin >> n;
	int i, number[100001];
	for (i = 0; i < n; i++)
	{
		cin >> number[i];
		S.insert(number[i]);
		Age[number[i]]++;
	}
	for (auto it = S.begin(); it != S.end(); ++it)
	{
		cout << *it << ":" << Age[*it] << endl;
	}
	return 0;
}