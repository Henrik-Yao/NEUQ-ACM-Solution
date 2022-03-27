## 1

```cpp
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int n;
string a, b, c;

void luohan(int num, string from, string to, string emp)
{
    if(num==1) cout<<from<<"->"<<to<<endl;
    else
    {
        luohan(num-1,from,emp,to);
        cout<<from<<"->"<<to<<endl;
        luohan(num-1,emp,to,from);
    }
}
int main()
{
    n = read();
    cin>>a>>b>>c;
    // n = 2;
    // a = 'a';
    // b = 'b';
    // c = 'c';
    luohan(n,a,c,b);
}
```

开始想复杂了，居然在推方案

哦，这周讲递归啊。。。

传参的地方想了一会儿，最后还是写了四个变量，不然还得在里面去找哪个是用来暂存的。

## 2

```cpp
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    char ch = getchar();
    int s = 0, w = 1;
    while(ch < '0' || ch > '9')
    {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0',
        ch = getchar();
    }
    return s * w;
}
const int N = 10010;
vector <int> G[N];
int beat[N];
int n,m;
bool vis[N];
int finded;
int savecheck[N];



bool dfs(int s)
{
    for(int i=0;i<G[s].size();i++)
    {
        int to = G[s][i];
        if(!vis[to])
            return false;
    }
    return true;
}
// int check(int np)
// {
//     bool flag = true;
//     for(int i=1;i<=np;i++)
//         if(beat[savecheck[i]]!=2) flag = false;
//     if(flag)
//         return true;
//     return false;
// }
int main()
{
//     freopen("read.in","r",stdin);
//     freopen("write.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a = read(), b = read();
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int k = read();
    while(k--)
    {
        memset(vis,0,sizeof(vis));
        memset(beat,0,sizeof(beat));
        int np = read();

        for(int i=1;i<=np;i++)
        {
            int da = read();
            vis[da] = true;
        }   
        int flag = true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            if(!dfs(i)) {flag = false;break;}
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    
    return 0;
}
```

蚌埠住了，题目理解完全错了，第一遍写的时候以为是让你判断能不能联通qwq

问了同学，然后认真理解了一下 **使其剩余的城市变成孤立无援**

嗯，阅读能力有待提高（不是

## 3

```cpp
#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int a[100000];

int main()
{
    int n = read();
    for(int i=1;i<=n;i++)
       a[i] = read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
       cout<<a[i]<<" ";
}
```

~~以上是错误示范~~

```cpp
#include <bits/stdc++.h>
using namespace std;
int a[1000];
int ass[1000];

void merge(int l, int r, int mid)
{
    int i = l, j = mid+1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
            ass[++k] = a[i++];
        else
            ass[++k] = a[j++];
    }
    while(i<=mid)
        ass[++k] = a[i++];
    
    while(j<=r)
        ass[++k] = a[j++];

    for(int i=0; i<r-l+1; i++)
        a[l+i] = ass[i+1];
}
void merge_sort(int l, int r)
{
    if(l>=r)
        return;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);

    merge(l,r,mid);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    merge_sort(1, n);

    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
```

这才是真正的mergesort 得似！

以为自己可以很快写出来

结果。。。还是去看了merge函数，然后while的范围写错了死循环了一下

我就是fw