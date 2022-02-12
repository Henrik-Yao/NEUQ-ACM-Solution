#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>nums;
//pre是当前下标值，pos是子序列长度 
bool visited(const vector<int>& nums, int pre, int pos) { 
		for(int i = pre + 1; i < pos; i++) {
			if (nums[i] == nums[pos]) return false;
		}
		return true;
}
	
	void dfs(const vector<int>& nums, int pre, int pos, vector<int>& stack, vector< vector<int> > & ans) {
		if (pos == nums.size()) return ;
		
		if ((stack.empty() || nums[pos] >= stack.back()) && visited(nums, pre, pos)) {
			stack.push_back(nums[pos]);
			if (stack.size() >= 2) ans.push_back(stack);
			dfs(nums, pos, pos + 1, stack, ans);
			stack.pop_back();
		}
		dfs(nums, pre, pos + 1, stack, ans);
	}
	int findSubsequences(vector<int>& nums) {
		vector<int> stack;//存放子序列的 
		vector< vector<int> > ans;//结果数组 
		dfs(nums, -1, 0, stack, ans);
		return ans.size();
    }
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		nums.push_back(a);
	} 
	int results;
	results=findSubsequences(nums);
	cout<<results<<endl;
} 
