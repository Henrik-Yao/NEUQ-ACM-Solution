# Week7-solution

## **7-1 词典**

set建立映射即可。。。。考试竟然没写，哭了

## **7-2 神秘密码**

用一个指针处理字符串，递归实现把[]中的东东展开

## **7-3 删除公共字符**

while套两个cin，考试忘了直接挂签到题。。。处理重复的字符串可以用vector先排序后unique去重，还可以用set自动去重，然后再一个个查看s1的字符是否在容器中，若不在则输出

## **7-4 最长有序子序列**

经典DP，向前遍历用方程dp[i]=max(dp[i],dp[j]+1)即可

## **7-5 0-1背包问题**

典中典DP，DP方程：dp[j]=max(dp[j],dp[j-t[i]]+v[i])，j代表背包容量，求塞入这个物品后的价值是否比之前更大