***

# **7-1 相邻数对**

> 给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。
>
> ### 输入格式:
>
> 输入的第一行包含一个整数n，表示给定整数的个数。 第二行包含所给定的n个整数。
>
> ### 输出格式:
>
> 输出一个整数，表示值正好相差1的数对的个数。
>
> ### 输入样例:
>
> ```in
> 6
> 10 2 6 3 7 8
> ```
>
> ### 输出样例:
>
> ```out
> 3
> ```
> 样例说明:
>值正好相差1的数对包括(2, 3), (6, 7), (7, 8)。 　　
>
>评测用例规模与约定:
>1<=n<=1000，给定的整数为不超过10000的非负整数。

注意到这些数字都是非负整数而且会重复，就可以用一个数组来存储下标对应数的数量，然后相减即可。

2有5个，3有4个，所以(2,3)有20个。

```C++
#include <iostream>
#include <algorithm>
using namespace std;
int num[10005];
int main(){
    int n;
    cin >> n;
	for(int i=0;i<n;i++){
		int j;
		cin >> j;
		num[j]++;
	}
	int sum=0;
	for(int i=0;i<10000;i++){
		sum+=num[i]*num[i+1];
	}
    cout << sum << endl;
}
```

***

# **7-3 两个有序序列的中位数**

> 已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列*A*0,*A*1,⋯,*A**N*−1的中位数指*A*(*N*−1)/2的值,即第⌊(*N*+1)/2⌋个数（*A*0为第1个数）。
>
> ### 输入格式:
>
> 输入分三行。第一行给出序列的公共长度N（0<N≤100000），随后每行输入一个序列的信息，即N个非降序排列的整数。数字用空格间隔。
>
> ### 输出格式:
>
> 在一行中输出两个输入序列的并集序列的中位数。
>
> ### 输入样例1:
>
> ```in
> 5
> 1 3 5 7 9
> 2 3 4 5 6
> ```
>
> ### 输出样例1:
>
> ```out
> 4
> ```
>
> ### 输入样例2:
>
> ```
> 6
> -100 -10 1 1 1 1
> -50 0 2 3 4 5
> ```
>
> ### 输出样例2:
>
> ```
> 1
> ```

归并的一个操作而已，从两边分别取最小的即可。

```C++
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int pa=0,pb=0;
    while(pa+pb<(2*n+1)/2-1){
        if(a[pa]>=b[pb]) pb++;
        else pa++;
    }
    if(a[pa]>b[pb]) cout << b[pb] << endl;
    else cout << a[pa] << endl;
    return 0;
}
```

***

# **7-4 二分查找**

> 输入n值(1<=n<=1000)、n个非降序排列的整数以及要查找的数x，使用**二分查找算法**查找x，输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。
>
> ### 输入格式:
>
> 输入共三行： 第一行是n值； 第二行是n个整数； 第三行是x值。
>
> ### 输出格式:
>
> 输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。
>
> ### 输入样例:
>
> ```in
> 4
> 1 2 3 4
> 1
> ```
>
> ### 输出样例:
>
> ```out
> 0
> 2
> ```

二分查找就是找中间值，然后比较中间值的大小和目标值的大小关系而已。

```C++
#include<iostream>
using namespace std;
int a[1005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int target,result=-1,times=0;
    cin>>target;
    int left = 0,right = n-1;
    while (left<=right){
        times++;
        int middle = (left+right)/2;
        if(target == a[middle]) {result=middle;break;}
        else if(target > a[middle]) left=middle + 1;
        else right=middle - 1;
    }
    cout<<result<<endl<<times<<endl;
    return 0;
}
```

***

# **7-6 二分查找**

> 对于输入的n个整数，先进行升序排序，然后进行二分查找。
>
> ### 输入格式:
>
> 测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n(1≤n≤100)，第二行输入n个各不相同的待排序的整数，第三行是查询次数m（1≤m≤100），第四行输入m个待查找的整数。
>
> ### 输出格式:
>
> 对于每组测试，分2行输出，第一行是排序后的升序的结果，每两个数据之间留一个空格；第二行是查找的结果，若找到则输出排序后元素的位置（从1开始，每两个数据之间留一个空格），否则输出0。
>
> ### 输入样例:
>
> ```in
> 9
> 4 7 2 1 8 5 9 3 6
> 5
> 10 9 8 7 -1
> ```
>
> ### 输出样例:
>
> ```out
> 1 2 3 4 5 6 7 8 9
> 0 9 8 7 0
> ```

二分查找+1,

先sort排一下/xyx。

```C++
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1005];
int main(){
    int n;
    while(cin>>n){
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        cout << a[0];
        for(int i=1;i<n;i++) cout << " " << a[i];
        cout << endl;
        
        int T;
        cin >> T;
        for(int j=0;j<T;j++){
            int target,result=-1,times=0;
            cin>>target;
            int left = 0,right = n-1;
            while (left<=right){
              int middle = (left+right)/2;
              if(target == a[middle]) {result=middle;break;}
              else if(target > a[middle]) left=middle + 1;
              else right=middle - 1;
           }
            if(j==0) cout << result+1;
            else cout << " " << result+1;
        }
        cout << endl;
    }
    return 0;
}
```

***

# **7-7 愤怒的牛**

> 农夫约翰建造了一座有*n*间牛舍的小屋，牛舍排在一条直线上，第*i*间牛舍在*x**i*的位置，但是约翰的*m*头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。
>
> 牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。John 决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？
>
> ### 输入格式:
>
> 第一行用空格分隔的两个整数*n*和*m*，*n*，*m*<=105；
>
> 第二行为*n*个用空格隔开的整数，表示位置*x**i*。*x**i*<*M**A**X**I**NT*
>
> ### 输出格式:
>
> 输出仅一个整数，表示最大的最小距离值。
>
> ### 输入样例:
>
> ```in
> 5 3
> 1 2 8 4 9
> ```
>
> ### 输出样例:
>
> ```out
> 3
> ```

这道题首先要把牛舍快排一下，然后利用二分答案，搜索当前情况下的最小距离是否符合要求，如果不符合就就比这个距离小，符合就比这个距离大。

```c++
#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int left=0,right= a[n-1]-a[0];
	while(left < right){
		long long middle = (left+right)/2, living_cows = 0;
		for(int i=0; i<n; i++){
			int t = i;
			while(a[i+1]-a[t]< middle && i < n)  i++;
			living_cows++;
		}
		if(living_cows >= m) left = middle + 1;
		else if(living_cows < m) right = middle;
	}
	cout << left-1 << endl;
	return 0;	
}
```

