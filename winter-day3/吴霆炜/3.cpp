#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > vs;
vector<int> v;
void dfs(int x,vector<int>& nums){
    if(x==nums.size()) {//递归出口
        if(v.size()>=2) vs.push_back(v);
        return;
    }
    if(v.size()==0||nums[x]>=v[v.size()-1]){//选
        v.push_back(nums[x]);
        dfs(x+1,nums);
        v.pop_back();//回溯
    }
    if(v.size()==0||nums[x]!=v[v.size()-1]) dfs(x+1,nums);//不选
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    dfs(0,nums);
    return vs;
}

int main(){
    vector<int>nums;
    scanf("%d",&n);
    nums.resize(n);
    for(int i = 0;i < n;i++)scanf("%d",&nums[i]);
    vector<vector<int> > ans = findSubsequences(nums);
    printf("%d\n",ans.size());
    return 0;
}