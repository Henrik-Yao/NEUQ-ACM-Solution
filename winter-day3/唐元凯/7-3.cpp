#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

set<stack<int>>s;

void sum(vector<int> &nums, int pos, stack<int>temp, int last) {
	const static int length = nums.size();
	if (pos == length)return;
	for (int i = pos; i < length; ++i)
	{
		if (temp.empty()) {
			temp.push(nums[i]);
			last = nums[i];
			sum(nums, i + 1, temp, nums[i]);
			temp.pop();
		}
		else if (nums[i] >= last) {
			temp.push(nums[i]);
			if (temp.size() == 1)sum(nums, i + 1, temp, nums[i]);
			else if (s.insert(temp).second)sum(nums, i + 1, temp, nums[i]);
			temp.pop();
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>nums(n);
	for (size_t i = 0; i < n; i++) cin >> nums[i];
	stack<int>temp;
	sum(nums, 0, temp, nums[0]);
	cout << s.size();
}