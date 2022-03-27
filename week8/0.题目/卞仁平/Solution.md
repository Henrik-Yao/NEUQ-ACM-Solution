# Solution

## 7-1最小失约

```c++
#include <bits/stdc++.h>
using namespace std;
struct shijian//定义一个结构体，连接起始时间和结束时间
{
    int a;
    int b;
};
bool cmp(shijian s1,shijian s2)//自己写了一个cmp函数来给sort用
{
    return (s1.b<s2.b);
}
void run()
{
    int n;
    cin>>n;
    shijian ps[n];
    int sum=1;
    for(int i=0;i<n;i++)
    cin>>ps[i].a>>ps[i].b;
    sort(ps,ps+n,cmp);//调用自己写的cmp作为标准来排序
    int end=ps[0].b;
    for(int j=1;j<n;j++)
    {
        if(ps[j].a>=end)
        {
            sum++;end=ps[j].b;//用贪心算法来实现
        }
    }
    cout<<n-sum<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    run();//直接运行函数
    return 0;

}
```



## 7-2跳一跳

```c++
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int findmax(int l,int r)//自己写查找最大值的函数
{
    int s=l+1;
    for(int i=l;i<=r;i++)
    {
        if(a[l]<a[i])
        {
            a[l]=a[i];
            s=i;
        }
    }
    return s;
}
int nmd(int l,int r)//不知道取啥名的函数
{
   
    for(int i=l;i<=r;i++)
        if(a[l]<a[i]+i-l)
            l=i;
    return l;
}
int main()
{
    int n;
	cin>>n;
	
	for(int i=0;i<n;i++)
    cin>>a[i];
    int k=0;
    int c=1;
    while(k+a[k]<n-1)
    {
        int t=a[k];
        int m;
        m=findmax(k,a[k]+k);
        k=nmd(m,t+k);
        c++;
    }
    //puts("%d",c);//这里用的puts好像哪里报错来着
    printf("%d\n",c);
    return 0;
}

```

