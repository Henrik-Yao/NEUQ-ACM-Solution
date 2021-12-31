# <center>ACM week8 习题题解</center>

<center>powered by hanhan</center>

### **7-1 最少失约**

###### 题目详情：

某天，诺诺有许多活动需要参加。但由于活动太多，诺诺无法参加全部活动。请帮诺诺安排，以便尽可能多地参加活动，减少失约的次数。假设：在某一活动结束的瞬间就可以立即参加另一个活动。

###### 输入格式:

首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n，代表当天需要参加的活动总数，接着输入n行，每行包含两个整数i和j（0≤i<j<24），分别代表一个活动的起止时间。

###### 输出格式:

对于每组测试，在一行上输出最少的失约总数。

###### 解题思路：

将数据以结束时间从小到大排序，然后遍历首位相接即可。

###### c++代码：

```c++
#include<iostream>
#include<algorithm>
using namespace std;

struct Program{
    int start;
    int end;
};

bool cmp(Program p1,Program p2){
    return(p1.end<p2.end);
}

Program pro[1000001];
int n;

void run(){
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>pro[i].start>>pro[i].end;
    }
    sort(pro,pro + n,cmp);
    int cnt=1;
    int curEnd=pro[0].end;
    for(int j=1;j<n;j++){
    if(pro[j].start >= curEnd){
    cnt++;
    curEnd=pro[j].end;
        }
    }
    cout<<n-cnt<<endl;
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
    run();
    }
    return 0;
}
```

### 7-2 跳一跳

这道题耗费了较长的时间，我硬是照着自己的思路把自己的bug一一查出。具体会在题目分析里讲解。

###### 题目详情：

**Drizzle** 面前有一条由一堆`非负整数`组成的道路，从第一个数字起步，每次他都能跳出不大于当前数字的距离，每个数字之间的距离为1，那么他最少需要跳多少次才能到达终点？

###### 要求:

输入：第一行输入道路中数字的个数`n`也就是道路的长度，第二行输入这n个数字

输出：输出一个数字，表示最少跳跃次数

###### 范围:

对于 20% 的数据：n≤100
对于 100% 的数据：n≤1000000
所有整数元素在`int`范围内

###### 题目分析：

思路：

1. 我的思路：

   可以直接计算最少次数。从第一次跳跃开始，遍历跳到可跳位置之后在跳可以调到的最远位置，记录此位置的最大值。进行第二次跳跃的时候，可以从第一次可跳最远距离开始，遍历跳到可跳位置之后在跳可以调到的最远位置并且记录此位置的最大值。直到超过最大值。

2. CSDN思路：

   可以直接计算最少次数。从第一次跳跃开始，查找跳到可跳位置之后在跳可以调到的最远位置的最大值所在的位置。从此位置开始，寻找跳到可跳位置之后在跳可以调到的最远位置。以此往复。（不太理解重复两次的用意）

###### c++代码：

1.  我的代码：


```c++
#include<iostream>
#include<ctime>
using namespace std;

int r0[100000001];
int n;
int ans;
int endi, first = 0;

int maxi(int first, int endi) {
    int max = 0;
    for (int i = first; i <= endi; i++) {
        max = max > r0[i] + i ? max : r0[i] + i;
    }
    return max;
}

int main() {
    //time_t begin, end;
    //double ret;
    //begin = clock();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r0[i];
    }
    endi = r0[first] + first;
    for (ans = 0; first < n - 1; ans++) {
        int temp = endi;
        endi = maxi(first, endi);//移动查找范围尾值
        first = temp;//查找范围首值
        cout << endi << first << endl;
    }
    cout << ans <<endl;
    //end = clock();
    //ret = double(end - begin) / CLOCKS_PER_SEC;
    //cout << "runtime:   " << ret << endl;
}
```
2. CSDN代码：


```c++
#include<iostream>
using namespace std;

int r0[100000001];
int n;
int ans;
int first = 0;

int findnum(int first, int endi) {
    int max = 0,temp = first + 1;
    for (int i = first; i < endi; i++) {
        if (max > r0[i]) {
            max = r0[i];
            temp = i; 
        }
    }
    return temp;
}

int linknum(int n, int m) {
    int ans = n;
    for (int i = ans; i <= m; i++) {
        if (r0[n] < r0[i] + (i - n)) {
            n = i;
        }
    }
    return n;
}

int main() {
    //time_t begin, end1;
    //double ret;
    //begin = clock();
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r0[i];
    }
    for (ans = 1; first + r0[first] < n - 1; ans++) {
        int temp = r0[first];//保存原数据
        int local = findnum(first, first + r0[first]);//查找起始位置
        first = linknum(local, first + temp);//跳入位置
    }
    cout << ans;
    //end1 = clock();
    //ret = double(end1 - begin) / CLOCKS_PER_SEC;
    //cout << "runtime:   " << ret << endl;
}
```

 