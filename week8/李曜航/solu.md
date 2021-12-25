## 7-1

**不会有人又不读题没看到时间从0开始吧？**

哦，不读题的又是我，那没事了

因为时间很少， 一个$dp[0][i] = max( dp[0][i], dp[0][k]+dp[k][i] );$就好了，也不用优化

有的人对着$dp[1][i] = max( dp[1][i], dp[1][k]+dp[k][i] );$冥思苦想

## 7-2

大无语x2

if(i+a[i]>=n)居然有人不是写的>=,因为你只要跳过了就行了呀

改了就好了qwq

反正如果 当前+当前能跳的最远 居然还没我以前的格子能跳的最远远，那直接continue吧

```cpp
int maxnext = 0;
for(int i=1;i<=n;i++)
{
    if(i+a[i]>=n){cout<<dp[i]+1<<endl;return 0;}

    if(a[i]>0 && i+a[i]>maxnext)
        for(int j=i+1;j<=i+a[i]&&j<n;j++)
            dp[j] = min(dp[j],dp[i]+1);

    maxnext = max(maxnext, i + a[i]);
}
```



