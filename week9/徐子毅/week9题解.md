***

# 7-1

>用i表示x轴上坐标为[i-1,i]的区间（区间长度为1），并给出n个不同的整数来表示n个这样的区间。现在要求画出几条线段覆盖住所有的区间，条件是：每条线段可任意长，但要求所画线段长度之和最小，并且线段的数目不超过m。
>
>### 输入格式:
>
>第一行输入表示区间个数n和最大线段数m。 第2行输入n个点的坐标。
>
>### 输出格式:
>
>输出能覆盖所有区间的线段最小长度和。

这道题手动解决一下就能发现，最开始最小长度和就是几个区间。而每一次要减少一个线就要把两个区间中间的缝隙连接起来。这个时候就应该尽量连接起大的区间。

```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ine[100005];
vector<int> cracks;
void breakline(int start,int end){
    int crack_num=0;
    int line_num=1;
    bool is_ine=true;
    for(int i=start+1;i<=end;i++){
        if(ine[i]==0&&ine[i-1]==1){
            line_num++;
            is_ine=false;
        }else if(ine[i]==1&&ine[i-1]==0){
            cracks.push_back(crack_num);
            crack_num=0;
            is_ine=true;
        }
        if(!is_ine) crack_num++;
    }
    return ;//line_num;
}
int main(){
    int n,m;
    cin >> n >> m;  
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    if(a[0]<0) {
        int move=a[0];
        for(int i=0;i<n;i++) a[i]-=move;
    }
    for(int i=0;i<n;i++) ine[a[i]]=1;
    breakline(a[0],a[n-1]);
    sort(cracks.begin(),cracks.end());
    int min_length=n;
    for(int T=0;T<cracks.size()-m+1;T++){
        min_length+=cracks[T];
    }
    cout << min_length << endl;
}
```

***

# 7-1

>有一个1×n的长方形，由边长为1的n个方格构成，例如，当n=3时为1×3的方格长方形如下图所示。求用1×1、1×2、1×3的骨牌铺满方格的方案总数。
>
>![1936.png](https://images.ptausercontent.com/13de27cd-8c68-4423-9cc5-4f89b9a6e5dd.png)
>
>### 输入格式:
>
>测试数据有多组，处理到文件尾。每组测试输入一个整数n（1≤n≤50）。
>
>### 输出格式:
>
>对于每组测试，输出一行，包含一个整数，表示用骨牌铺满方格的方案总数。

递归，第n个格子的摆法是第n-1个格子的摆法后面摆一个1x1加上第n-2个格子的摆法后面摆一个1x2加上第n-3个格子后面的摆一个1x3。

```C++
#include <iostream>
using namespace std;
unsigned long long array[55];
int main(){
	int n;
	array[1]=1;
	array[2]=2;
	array[3]=4;
	for(int i=4;i<=50;i++){
		array[i]=array[i-1]+array[i-2]+array[i-3];
	}
	while(cin >> n) cout << array[n] << endl;
	return 0;
}
```

