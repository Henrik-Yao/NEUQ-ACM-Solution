# 7-1

暴力筛直接过

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //先用暴力筛看看过得了不
    int a,b;
    while(cin>>a>>b)
    {
    int ff=0;
    for(int i=a;i<=b;i++)
    {
        int f=1;
        
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                f=0;
                break;
            }
        }
        if(f)
        {ff++;}
        if(ff==1&&f)
        cout<<i;
        else if(ff>1&&f)
        cout<<" "<<i;
    }
    cout<<endl;
    
    }
}
```



# 7-2

找规律，最后发现就是个斐波那契数列

```c++
	int a[41];
    a[0]=0;a[1]=1;a[2]=2;
    for(int i=3;i<=41;i++)
    a[i]=a[i-1]+a[i-2];
```



# 7-3

#### 1.week4-3baoli

用的暴力筛

超时了

#### 2.week4-3aishi

用的埃氏筛

也超时了

#### 3.week4-3xuanshen

抄的玄神的“埃氏筛”

是不是叫埃氏筛我不知道

但是原理勉强看懂了

```c++
for(int i=2;i<=n;i++)
    {
        if(is[i])continue;
        s++;
        for(int j=i;j<=n;j+=i)
        //我试着用long long j=i*i,pta提示段错误？？？
        is[j]=1;
    }
```

用j的那个循环就是标记是i的倍数的数字不为素数

所以简化了不少

但是这个代码好像还可以再简化，就是注释那样

#### 4.week4-3ola

用的欧拉筛

```c++
for(int i=2;i<=n;i++)
    {
        if(is[i])
        a[f++]=i;
        for(int j=0;j<f&&i*a[j]<=n;j++)
        {
            is[i*a[j]]=0;
            if(i%a[j]==0)
            break;
        }
    }
```

欧拉筛和上面那个应该都是基于埃氏筛继续简化的

就是减少运算次数

这个就是用最小素因子来筛选的，时间复杂度更低



# 7-4

快速幂

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
//简化的快速幂
{
    int t;
    cin>>t;
    while (t--)
    {
        long long a,b,c;
        long long s=1;
        cin>>a>>b>>c;
        while(b>0)
        {
            if(b%2==1)
            s=s*a%c;

            b/=2;
            a=a*a%c;
        }
        cout<<s<<endl;
    }
}
```





