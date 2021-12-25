# solution

**7-1 铺满方格**

手动搜索找到规律：`ans[x]=ans[x-3]+ans[x-2]+as[x-1];`，递推即可得到答案。