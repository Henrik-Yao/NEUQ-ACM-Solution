#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));//用vector来初始化dp数组，没区别（方便初始化条件）
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {//w的变化对应当背包剩余的不同容量
            if (w - wt[i-1] < 0) {
                // 这种情况下只能选择不装入背包
                dp[i][w] = dp[i - 1][w];
            } else {
                // 装入或者不装入背包，择优
                dp[i][w] = max(dp[i - 1][w - wt[i-1]] + val[i-1], 
                               dp[i - 1][w]);
            }
        }
    }
    
    return dp[N][W];
}

int main ()
{
    int n,c;
    while(cin>>n,cin>>c)
    {
        int temp;
        vector<int>wt;
        vector<int>val;
        wt.push_back(0);//这两行是初始化一下边界条件
        val.push_back(0);
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            wt.push_back(temp);
        }
        for(int j=1;j<=n;j++)
        {
            cin>>temp;
            val.push_back(temp);
        }
        int res=knapsack(c,n,wt,val);
        cout<<res<<endl;
    }
    return 0;
}
