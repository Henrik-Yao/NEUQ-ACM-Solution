# ACM Week9 & 第四次双周赛 题解

确实是期末了。

### 7-1 求解区间覆盖问题 

###### 题目详情：

用i表示x轴上坐标为[i-1,i]的区间（区间长度为1），并给出n个不同的整数来表示n个这样的区间。现在要求画出几条线段覆盖住所有的区间，条件是：每条线段可任意长，但要求所画线段长度之和最小，并且线段的数目不超过m。

###### 输入格式:

第一行输入表示区间个数n和最大线段数m。 第2行输入n个点的坐标。

###### 输出格式:

输出能覆盖所有区间的线段最小长度和。

###### 解题思路：

隔板法，先用一段囊括所有的区间，在根据题目区间段的空隙进行分段。

###### c++代码：

```c++
#include<iostream>
#include<algorithm>
using namespace std;

int area[10086];
int m, n;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> area[i];
    sort(area, area + m);//排序。方便计算每个空隙的长度
    int ans = area[m - 1] - area[0] + 1;
    for (int i = 1; i < m; i++) area[i - 1] = area[i] - area[i - 1] - 1;
    area[m - 1] = 0;
    sort(area, area + m - 1, cmp);//排序，将空隙长度排序
    n = n - 1;
    while (n--) {
        ans -= area[n];
    }
    cout << ans;
}
```

### 7-1 铺满方格

###### 题目详情：

有一个1×n的长方形，由边长为1的n个方格构成，例如，当n=3时为1×3的方格长方形如下图所示。求用1×1、1×2、1×3的骨牌铺满方格的方案总数。

###### 输入格式:

测试数据有多组，处理到文件尾。每组测试输入一个整数n（1≤n≤50）。

###### 输出格式:

对于每组测试，输出一行，包含一个整数，表示用骨牌铺满方格的方案总数。

###### 解题思路：

跟跳楼梯一个道理，求递推公式，F(n) = F(n - 1) + F(n - 2) + F(n - 3);

###### c++代码：

```c++
#include<iostream>
using namespace std;

int main() {
    int a;
    while (cin >> a) {
        long long int ans[4] = { 0,1,2,4 };
        for (int i = 4; i <= a; i++) {
            ans[i % 4] = ans[(i + 1) % 4] + ans[(i + 2) % 4] + ans[(i + 3) % 4];
        }
        cout << ans[a % 4] << endl;
    }

}
```

