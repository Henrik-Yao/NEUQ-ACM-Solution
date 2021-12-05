#include <iostream>
using namespace std;

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i=1,n,res=-10000000;
        cin>>n;
        int dp[n+1]={1},a[n+1];
        for(int j=1;j<=n;j++)//dp数组的初始化，每个数字最少长度为
        {
            cin>>a[j];
            dp[j]=1;
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<j;k++)//对这个数的前面所有数遍历，找到最长的子序列作为这个状态的最长子序列
            {
                if(a[j]>a[k])//在后一个数出现了大于之前的数
                {
                    dp[j]=max(dp[j],dp[k]+1);//让当前的最长子序列等于前面的最长子序列+1
                }
            }
            res=max(dp[j],res);
        }
         cout<<res<<endl; //输出结果       
        if(t) cout<<endl;//题目的小坑，不过不太能理解为什么会是每组数据之间空两行
    }
    return 0;
}