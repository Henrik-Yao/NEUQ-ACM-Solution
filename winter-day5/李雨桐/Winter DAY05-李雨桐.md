## Winter DAY05-李雨桐

### 7-1 相邻数对

给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。

### 输入格式:

输入的第一行包含一个整数n，表示给定整数的个数。 第二行包含所给定的n个整数。

### 输出格式:

输出一个整数，表示值正好相差1的数对的个数。

### 输入样例:

```in
6
10 2 6 3 7 8结尾无空行
```

### 输出样例:

```out
3



结尾无空行
```

### 样例说明:

值正好相差1的数对包括(2, 3), (6, 7), (7, 8)。 　　

### 评测用例规模与约定:

1<=n<=1000，给定的整数为不超过10000的非负整数。

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
typedef pair <int,int> pir;
pir a[1005];

unordered_map <int,int> mp;
int main()
{
	int n,val;
    int cnt=0,ans=0;
	cin >> n;
	for(int i=0;i<n;i++)
    {
		cin>>val;
		mp[val]++;
	}

	for(auto iter = mp.begin();iter != mp.end();iter++)
	{
		cnt++;
		if(mp.count(iter->first+1))
		ans += mp[iter->first+1];
	}

	cout<<ans<<endl;

}


```

------------------

### 7-3 两个有序序列的中位数

已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列*A*0,*A*1,⋯,*A**N*−1的中位数指*A*(*N*−1)/2的值,即第⌊(*N*+1)/2⌋个数（*A*0为第1个数）。

### 输入格式:

输入分三行。第一行给出序列的公共长度N（0<N≤100000），随后每行输入一个序列的信息，即N个非降序排列的整数。数字用空格间隔。

### 输出格式:

在一行中输出两个输入序列的并集序列的中位数。

### 输入样例1:

```in
5
1 3 5 7 9
2 3 4 5 6结尾无空行
```

### 输出样例1:

```out
4



结尾无空行
```

### 输入样例2:

```
6
-100 -10 1 1 1 1
-50 0 2 3 4 5
```

### 输出样例2:

```
1
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int arr[200005];

int main()
{
	int n;
	cin>>n;

	for(int i=1;i<=2*n;i++)
		cin >> arr[i];
	sort(arr+1,arr+2*n+1);

	cout<<arr[(2*n+1)/2];

	return 0;
}


```

---------------------

### 7-4 二分查找

输入n值(1<=n<=1000)、n个非降序排列的整数以及要查找的数x，使用**二分查找算法**查找x，输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。

### 输入格式:

输入共三行： 第一行是n值； 第二行是n个整数； 第三行是x值。

### 输出格式:

输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。

### 输入样例:

```in
4
1 2 3 4
1结尾无空行
```

### 输出样例:

```out
0
2结尾无空行
```

### 代码：

```c++
#include<iostream>
using namespace std;
int cnt=0;
int a[1005];
int searc(int a[],int s,int e,int x)
{
    while(s<=e)
    {
    cnt++;
    int mid=(e+s)/2;

    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
      e=mid-1;
   else
       s=mid+1;

    }
    return -1;

}
int main()
{
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cin>>x;

  cout<<searc(a,0,n-1,x)<<endl;
  cout<<cnt<<endl;
  
  return 0;
}


```

-------------------

### 7-6 二分查找

对于输入的n个整数，先进行升序排序，然后进行二分查找。

### 输入格式:

测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n(1≤n≤100)，第二行输入n个各不相同的待排序的整数，第三行是查询次数m（1≤m≤100），第四行输入m个待查找的整数。

### 输出格式:

对于每组测试，分2行输出，第一行是排序后的升序的结果，每两个数据之间留一个空格；第二行是查找的结果，若找到则输出排序后元素的位置（从1开始，每两个数据之间留一个空格），否则输出0。

### 输入样例:

```in
9
4 7 2 1 8 5 9 3 6
5
10 9 8 7 -1
```

### 输出样例:

```out
1 2 3 4 5 6 7 8 9
0 9 8 7 0
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int a[105];

int searc(int tar, int n);

int main()
{
	int n,m;
	while(cin>>n)
    {
		for(int i=0;i<n;i++)
			cin >> a[i];

		sort(a,a+n);

		for(int i = 0; i < n-1; i++)
			cout<<a[i]<<" ";

		cout<<a[n-1]<<endl;
		cin>>m;

		int tar;
		for(int i=0;i<m;i++)
        {
			cin>>tar;
			cout<<searc(tar,n)+1;
			if(i!=m-1)
                cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}

int searc(int tar, int n)
{
	int mid;
	int l=0,r=n-1;
	while(l<=r)
    {
		mid=l+(r-l)/2;

		if(a[mid]==tar)
			return mid;

		if(tar<a[mid])
			r=mid-1;
        else
			l=mid+1;
	}
	return -1;
}


```

-------------------

### 7-7 愤怒的牛

农夫约翰建造了一座有*n*间牛舍的小屋，牛舍排在一条直线上，第*i*间牛舍在*x**i*的位置，但是约翰的*m*头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。

牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。John 决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？

### 输入格式:

第一行用空格分隔的两个整数*n*和*m*，*n*，*m*<=105；

第二行为*n*个用空格隔开的整数，表示位置*x**i*。*x**i*<*M**A**X**I**NT*

### 输出格式:

输出仅一个整数，表示最大的最小距离值。

### 输入样例:

```in
5 3
1 2 8 4 9结尾无空行
```

### 输出样例:

```out
3



结尾无空行
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

long long a[100005]={0};
long long n,m;

bool vis(int x);

int main()
{
    long long i,mid;
    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    sort(a,a+n);
    long long l=a[0],r=a[n-1]-a[0];
    long long flag;

    while(l<=r)
    {
        mid=(l+r)/2;
        if(vis(mid)==true)
        {
            l=mid+1;
            flag=mid;
        }
        else
            r=mid-1;
    }

    cout<<flag<<endl;
    return 0;
}

bool vis(int x)
{
    long long cnt=1,now=a[0];
    for(long long i=1; i<n; i++)
    {
        if(a[i]-now>=x)
        {
            now=a[i];
            cnt++;
            if(cnt>=m)
            {
                return true;
            }
        }
    }
    return false;
}


```

----------------------

