#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>nums;
//pre�ǵ�ǰ�±�ֵ��pos�������г��� 
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
		vector<int> stack;//��������е� 
		vector< vector<int> > ans;//������� 
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
