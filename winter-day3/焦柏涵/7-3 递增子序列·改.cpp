#include <bits/stdc++.h>
using namespace std;
int num=0;
class solve{
public:
	vector<vector <int> > res;
    vector<int> tmp;
    vector<int> nums;
    void dfs(int site,int n,vector<int>& nums){
        if(site == nums.size()){
            if(tmp.size() >= 2)
            {
            	res.push_back(tmp);
            	num++;
			}
            return;
        }
        if(nums[site] >= n){
            tmp.push_back(nums[site]);
            dfs(site+1,nums[site],nums);
            tmp.pop_back();
        }
        
        if(nums[site] != n){
            dfs(site+1,n,nums);
        }
    }
    int search_nums(vector<int>& nums) {
        dfs(0,INT_MIN,nums);
        return num;
    }
} a;
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		a.nums.push_back(m);
	}
	cout<<a.search_nums(a.nums);
}
