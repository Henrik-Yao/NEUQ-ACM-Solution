#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res; // 储存结果
vector<int> nums; // 读入数组
vector<int> path; // 子集
void backTracking(vector<int>& nums, int startIdx) {
	if (path.size() > 1) res.push_back(path); // 当子集长度大于等于2时存入结果向量中，子集数量自然加一
	unordered_set<int> uset; // 用来去重（只在 startIdx 向后所有的元素这一层，不影响上下层）
	for (int i = startIdx; i < nums.size(); i++) {
		// 如果 子集不空且当前索引位置值大于之前存入子集最后一个值 或者当前索引位置值在 uset 中出现过说明同层重复
        // uset.find(x) 查询 uset 中的 x 如果查不到返回 uset.end() 查到返回迭代器
		if ((!path.empty() && nums[i] < path.back()) || uset.find(nums[i]) != uset.end()) continue;
		uset.insert(nums[i]);
		path.push_back(nums[i]);
		backTracking(nums, i + 1);
		path.pop_back(); // 状态复原
	}
}
vector<vector<int>> findSubSequences(vector<int>& nums) {
	res.clear(); path.clear();
	backTracking(nums, 0);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back(num);
	}
	vector<vector<int>> ans = findSubSequences(nums);
	cout << ans.size() << endl;
	return 0;
}