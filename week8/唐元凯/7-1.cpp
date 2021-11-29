#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Plan
{
	int start = 0, end = 0;
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<Plan>a;
		Plan temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp.start >> temp.end;
			a.emplace_back(temp);
		}
		sort(a.begin(), a.end(), [](const Plan &s1, const Plan &s2) {return s1.end < s2.end; });
		int cnt = 1;
		int cur = a[0].end;
		for (int i = 0; i < n; i++)
		{
			if (a[i].start >= cur) {
				cnt++;
				cur = a[i].end;
			}
		}
		cout << n-cnt << endl;
	}
}