# week 8 solution

### 7-1 

这道题一开始以为是dp,结果磕了半天才知道是贪心QAQ

贪心是一种特殊的dp,都是通过最优子问题的解决来得出整个问题的解,只不过贪心只考虑眼前的最优,而没有大局观.所以看到网上有大佬说贪心是一种很不稳定的算法.

这题的贪心策略是--找到当前结束最早的活动.从逻辑方面很好理解,只要我结束的早,就有更多的时间去参加更多的活动.数学方面貌似也可以用数学归纳法证明?(别看我,我不会)

### 7-2

这题两遍就过了,还是挺惊喜的,毕竟第一题花了不少时间,而且代码貌似算是很精简的

```
#include <iostream>
using namespace std;
int a[1000010];
int main()
{
    int n;
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
        cin>>a[i];
    j=1;
    int pace=0;
    int maxm;
    while(1)
    {
        if(a[j]>=n-j)
            break;
        int step=0;
        for(i=1;i<=a[j];i++)
        {
            if(i+a[i+j]>step)
            {
                step=i+a[i+j];
                maxm=i;
            }
        }
        j+=maxm;
        pace++;
    }
    pace++;
    cout<<pace;
    
}
```

总的来说就是,在当前可以跳到的区域内,找到最优的落地点(跳跃距离+落地点可跳跃距离)