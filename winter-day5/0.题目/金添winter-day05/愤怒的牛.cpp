#include <bits/stdc++.h>
using namespace std;
//贪心+二分
//思路：利用二分把几乎所有可能的答案列出来，通过贪心判断该值是否满足题意，并通过反馈来修正
int cnt;//此时塞了多少牛
int map1[100000]; //农舍地图
int n,m;
bool judge(long long ans) //判断这个和答案大小关系
{
    int cnt=0;//cnt每次要进行一次重置
    cnt++;//第一头牛放入
    long long last=map1[0]; //最近的节点
    for(int i=1;i<n;i++)
    {
        if(map1[i]-last>=ans)
        {
            cnt++; //该点可以！将牛塞入
            last=map1[i]; //最近节点更新
            if(cnt>=m)
            return true; //塞的牛可以达到要求值！ans可以再大一点
        }
    }
    return false; //塞的牛达不到要求，ans应该变小一点。
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>map1[i];
    }
    sort(map1,map1+n);
    long long left=0;
    long long right=map1[n-1]-map1[0];
    while(right>=left)
    {
        long long mid=(left+right)/2;
        if(judge(mid))
        {//ans可以再大一点
            left=mid+1;
        }
        else
        {//ans应该小一点
            right=mid-1;
        }
    }
    cout<<left-1;
    return 0;
}