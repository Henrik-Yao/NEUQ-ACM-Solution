#include <bits/stdc++.h>
using namespace std;

set <vector<int>> ans;
vector <int> t;
int a[20],n;
void searc(int x)
{

	if (t.size()>=2)
	{
		ans.insert(t);
	}
	for (int i=x;i<n;i++)
	{
		if (t.empty()||a[i] >= t[t.size() - 1])
		{
			t.push_back(a[i]);
			searc(i + 1);
			t.pop_back();
		}
		else searc(i + 1);
	}
}
int main()
{

	cin>>n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	searc(0);
	cout<<ans.size()<<endl;
	return 0;
}
