# 我以后一定周一周二就把题解写完.jpg
## 7-1
我考试会写不出来这个题
只有有足够时间+玄神提示的坑点才能做。

这个题解认真写.jpg
```cpp
struct per
{
    bool sex; //0 boy, 1 girl
    int mo;//老妈id
    int fa;//老爸id
}p[100001];
```
用结构体存数据
读入见代码
坑点：有一个坑点是“父母”也可能会结婚(来自玄神)
```cpp
//以下尊听玄神教诲，爸妈也会被判断，这里之前被卡了。。。
p[p[id].fa].sex = 0;//老爸记录性别
p[p[id].mo].sex = 1;//老妈记录性别
```

if((p[a].sex^p[b].sex)==0) 异或判男酮
下面是judge函数
```cpp
void judge(int x, int y, int step)
{
    if(x==-1||y==-1||flag) return; //已经有-1了，回溯，这个不搜
    if(step==4){return;}//4级搜完判断（因为我本人辈分是0--不要乱想！爸妈是1，祖父是2，曾祖父是3，那个什么祖父是4就回溯了）

    // printf("x:%d ,y:%d\n",x,y);//debug的时候可以打印输出一下搜了哪些
    
	//同父异母也是近亲结婚。。。无语了我怎么连这个都不知道，开始还写的&&
    if(p[x].fa!=-1&&(p[x].fa==p[y].fa) || p[x].mo!=-1&&(p[x].mo==p[y].mo))
    	{is = true; flag = true; return;}
    else
    {
        //四个判断：双方父亲，双方母亲，男方父亲和女方母亲，男方母亲和女方父亲
        judge(p[x].fa,p[y].fa,step+1);
        judge(p[x].mo,p[y].mo,step+1);
        judge(p[x].fa,p[y].mo,step+1);
        judge(p[x].mo,p[y].fa,step+1);
    }
}
```

## 7-2
读题啊大哥，这个考试完全不读题？
完全被作业的线筛搞魔怔了
每个不小于6的偶数都是两个素数之和这句话被我吞了啊
不说了。。。
奇数如果可以被一个奇数质数相减不就是偶数吗 所以最多三次
偶数是两次，除了2（说到这里玄神的代码可以被hack233333）
然后确实有一种，就是奇数-2也是质数的话，那么也是两次
总共就这三种情况。
## 7-3
**我也不知道说什么，但是我读不出题的意思**
但各边并非按端点编号顺序排列。我看到这句话，我以为是这个有向图不是从a到b，有可能是b到a，不然样例2怎么可能输出3呢？
我就是想不到为什么要遍历所有的点。我想不通。
代码加一行就解决的事情，但是我就是读不出题干
我还考什么试啊？题都读不懂）
## 7-4
第一遍交的时候数组开小了，改大了。每次标记这次搜到的联通块，有一块就cnt++
## 7-5
  **题读错了T*D能做的出来就有鬼了**
  我是在不知道怎么办了。
  一个是下标从0开始，我读不出这个条件；二是我以为是跳到下标0就结束。我是在不知道为什么我可以连读错两个地方。
  退队吧。