week8题解

思路：一开始我是想使用dp的，但是看了好久这道题dp的话，我认为可以dp【现在的时间】【】

下一个括号没想明白怎么设，其实这道题的决定因素是结束时间，按照结束时间去排序，然后遍历求。因为任何一个活动的开始时间一定早于结束时间，按照结束时间排序是不会错的。

#include<iostream>
#include<algorithm>
using namespace std;
struct sj {
    int a;
    int b;
}jl[105];//定义时间结构体，并记录起始始末时间数组
bool yd(sj s1, sj s2) 
{
    return s1.b < s2.b;
}//判断s1的结束时间是否小于s2
int main()
{
    int T, n;
    cin >> T;
    for (int w = 0; w < T; w++) {
        cin >> n;
        for (int j = 0; j < n; j++) 
        {
            cin >>jl[j].a >> jl[j].b;
        }//记录数据
        sort(jl, jl + n, yd);//按照终止时间排序
        int j = 0;
        int count = 1;//因为第一个默认是直接参加
        for (int i = 1; i < n; i++)
        {
            if (jl[i].a >= jl[j].b)//如果现在这个活动的开始时间比第j个活动的结束时间晚 
            {
                j = i;//那么这个活动可以参加，同时将现在的时间记录为这个活动的结束时间
                count++;//事件个数++
            }
        }
        cout << n - count << endl;//失约个数
    }
}

跳一跳

这道题本质应该是贪心算法吧，贪心算法相较于动态规划要简单多了，但是它找到的是局部最优解，也就是说可能还是会出先漏的情况。

思路：对于每一个点，在其范围内选取另一个位置得到的范围去一一比较得到最大的范围就是这一步应该跳出的步数，同时将位置更改为这个点，进行下一次的跳跃，直到范围可以调到最后一个，结束。

#include<iostream>
using namespace std;
const int Max = 1e6 + 7;
int a[Max];
int find(int n, int m) {
	int ans = n + 1;
	for (int i = n; i <= m; i++) {
		if (a[n] < a[i]) {
			a[n] = a[i];
			ans = i;
		}
	}
	return ans;
}
int link(int n, int m) {
	int ans = n;
	for (int i = ans; i <= m; i++) {
		if (a[n] < a[i] + (i - n)) {
			n = i;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = 0, tmp = 1; // 最少跳一次
	while (k + a[k] < n - 1) {
		int p = a[k]; // 防丢失
		int m = find(k, a[k] + k); // 寻找k到a[k]+k之内最大值所在的位置
		k = link(m, p + k); // 寻找要跳入的位置上
		tmp++;
	}
	cout << tmp << endl;
}