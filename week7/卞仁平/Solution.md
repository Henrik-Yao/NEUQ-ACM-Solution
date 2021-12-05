# Solution

## 7-1

应该算是map的使用教程了（doge）

`map<string,string>zidian;`

这样定义一个字符串对应字符串的map映射就好了

剩下的直接看代码吧，没啥好说的

```c++
#include <bits/stdc++.h>
using namespace std;
map<string,string>zidian;
int main()
{
    int n;
    int m;
    cin>>n>>m;
    while(n--)
    {
        string a,b;
        cin>>a;cin>>b;
        zidian[b]=a;
    }
    while(m--)
    {
        string x;
        cin>>x;
        if(zidian[x]=="")
        cout<<"eh\n";
        else 
        cout<<zidian[x]<<endl;
    }
    return 0;
}
```



## 7-2

压缩密码，看着头疼，用递归解决的

```c++
string read()//递归读取函数
{
    string s="";
    string t;
    char x;
    int n;
    while(cin>>x)
    {
        if(x=='[')//当读入[的时候
        {
            cin>>n;//读入数字
            t=read();//继续读取
            while(n--)//s就是数字后面的所有字符
            s+=t;
        }
        else
        {
            if(x==']')
            return s;//解压缩
            else s+=x;//继续下一层
        }
    }
}
```



## 7-3

我不会，我不知道，我不理解，我不懂（doge）

我用的erase解决的（应该算是投机取巧了）

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    while(getline(cin,a),getline(cin,b))//用getline可以读入空格
    {
        int al=a.length();
        int bl=b.length();
        for(int i=0;i<al;i++)
        {
            for(int j=0;j<bl;j++)
            {
                if(a[i]==b[j])
                {
                    a.erase(i--,1);
                    //双层循环判断是否一样
                    //erase用的时候要注意字符串长度的缩短，所以是i--
                }
            }
        }
        cout<<a<<endl;
    }
    return 0;
}
```



## 7-4

最典型的dp了属于是

我用的也是最简单的dp，不会那个更np的贪心+二分算法

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int lis[n];//定义一个lis数组用来存要求的最大值
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            lis[i]=1;//赋初值为1
        }
        //memset(lis,1,sizeof(lis));
        //查到的memset给int型的数组赋非零值会有点问题
        for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        if(a[i]>a[j])
        {
            lis[i]=max(lis[j]+1,lis[i]);//就是判断lis数组该取何值
        }
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,lis[i]);//得到lis数组的最大值
        cout<<ans<<endl;
        if(t) printf("\n");
    }
    return 0;
}
```



## 7-5

使用了二维数组来存取数据

```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,c;
int main()
{
    //while(~scanf("%d %d",n,c))
    while(cin>>n>>c)
    {
        int w[N],v[N];
        for(int i=1;i<=n;i++)
        cin>>w[i];
        for(int i=1;i<=n;i++)
        cin>>v[i];
        int f[N][N];//定义的二维数组
        memset(f,0,sizeof(f));//清零
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=c;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=w[i])//核心代码
                f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);//判断哪种情况价值更大
            }
        }
        int ans=0;
        for(int i=0;i<=c;i++)
        ans=max(ans,f[n][i]);//得到装满的时候的最大价值
        cout<<ans<<endl;
    }
    return 0;
}
```

