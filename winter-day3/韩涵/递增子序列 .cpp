#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;

set<vector<int>>result;
vector<int>temp;
int nums[20];
int n;

void F(int k)
{
	int i;
	if (temp.size() >= 2)
	{
		result.insert(temp);
	}
	for (i = k; i < n; i++)
	{
		if (temp.empty() || nums[i] >= temp[temp.size() - 1])
		{
			temp.push_back(nums[i]);
			F(i + 1);
			temp.pop_back();
		}
		else F(i + 1);
	}
}
int main()
{
	int  i;
	cin >> n;
	for (i = 0; i < n; i++) cin >> nums[i];
	F(0);
	cout << result.size() << endl;
	return 0;
}