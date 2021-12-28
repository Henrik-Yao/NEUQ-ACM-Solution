#include<iostream>
#include<cmath>
#include<vector>
#include<set>
using namespace std;
set<vector<int>>res;
vector<int>temp;
int nums[20], n;
void solution(int k)
{
	int i;
	if (temp.size() >= 2)
	{
		res.insert(temp);
	}
	for (i = k; i < n; i++)
	{
		if (temp.empty()||nums[i] >= temp[temp.size() - 1])
		{
			temp.push_back(nums[i]);
			solution(i + 1);
			temp.pop_back();
		}
		else solution(i + 1);
	}
}
int main()
{
	int  i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	solution(0);
	cout << res.size() << endl;
	return 0;
}