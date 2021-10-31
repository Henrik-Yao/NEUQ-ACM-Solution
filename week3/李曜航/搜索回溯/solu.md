## 7-1

这个，题目上，为什么，他的示范，是中文的符号
蚌埠住
并查集添加到联通当前城市的安全区
[并查集](https://zhuanlan.zhihu.com/p/93647900)

我们用一个数组rank[]记录每个根节点对应的树的深度（如果不是根节点，其rank相当于以它作为根节点的子树的深度）。一开始，把所有元素的rank（秩）设为1。合并时比较两个根节点，把rank较小者往较大者上合并。

```CPP
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);    //先找到两个根节点
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}
```

```cpp
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}
```

路径压缩

```cpp
inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int find(int x)
{
    if(fa[x] == x)
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}
```


## 7-2

这个不能暴搜。。。。。
上去直接超时qwq
然后看了看好像有类SPFA的做法，然后去尝试
为什么我写出来就错了呢？


## 7-3 *****

这个相对就很简单了
写一个update，然后一个display数组存当前显示数值
如果update了display还是0，那么说明周围没有炸弹，直接update所有周边的格子

然后最后print（）一下就好

## 7-4
直接搜索
~~当然是超时~~

想到了并查集，但是没想到怎么去映射的
看的别人映射(i,j)=i*n+j;

哎，最后又不是独立完成的。。。。我就是fw

**普 及 -**

汗