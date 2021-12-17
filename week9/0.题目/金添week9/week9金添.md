# week9 题解
### 双周赛 线段覆盖
基本思路是，首先设定一条线段将整个所有区间都覆盖，然后根据所给的线段最大数值，优先截去间隔较大的间隔，从而转化为一个线段截取问题。
```C++
#include <bits/stdc++.h>
using namespace std;
int interval[100];//记录区间
int gap[100];//记录区间的间隔
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>interval[i];
    }
    sort(interval,interval+n);//将区间长度从小到大排序
    int len=interval[n-1]-(interval[0]-1);//假设一条线段将所有区间全覆盖，然后再减去大的间隔即可；
    for(int i=0;i<n-1;i++)
    {
        gap[i]=interval[i+1]-(interval[i]+1);//计算每两个区间之间的间隔
    }    
    sort(gap,gap+n-1,cmp);//将区间间隔从大到小排序
    for(int i=0;i<=m-2;i++)//尽可能的删去大区间
    {
        len-=gap[i];
    }
    cout<<len;
    return 0;  
}
```
### week 9 方格覆盖
经典的递归问题，首先考虑格子数为n个，可以由n-1,n-2,n-3格子时依次进行递归.
```C++
#include <bits/stdc++.h>
using namespace std;
long long a[51];
long long ans(long long n)//经典递归问题
{
    if(a[n])
    return a[n];
    else if(n==1)
    return a[1]=1;
    else if(n==2)
    return a[2]=2;
    else if(n==3)
    return a[3]=4;
    else
    return a[n]=ans(n-1)+ans(n-2)+ans(n-3);
}
int main()
{
    long long n;
    while(cin>>n)
    {
        cout<<ans(n)<<endl;
    }
    return 0;
}
```






