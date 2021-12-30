#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int>a; a.reserve(200001);
	int temp;
	for (int i = 0,length=n*2; i <length; i++)
	{
		cin >> temp;
		a.emplace_back(temp);
	}
	sort(a.begin(), a.end());
	int mid = (2 * n + 1) / 2 - 1;
	cout << a[mid];
}