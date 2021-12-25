***

# 7-1 

>某天，诺诺有许多活动需要参加。但由于活动太多，诺诺无法参加全部活动。请帮诺诺安排，以便尽可能多地参加活动，减少失约的次数。假设：在某一活动结束的瞬间就可以立即参加另一个活动。
>
>### 输入格式:
>
>首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n，代表当天需要参加的活动总数，接着输入n行，每行包含两个整数i和j（0≤i<j<24），分别代表一个活动的起止时间。
>
>### 输出格式:
>
>对于每组测试，在一行上输出最少的失约总数。

这道题贪心算法。首先需要将时间表按照结束时间排序，哪个项目的结束时间少，就能更好的利用时间，在判断这个最快结束的下一个能不能参加即可。

```C++
#include <iostream>
using namespace std;
struct timestable{
    int start;
    int end;
};
int main(){
    int abc;
    cin >> abc;
    for(int kkk=0;kkk<abc;kkk++){
        int n;
        cin >> n;
        timestable ts[n];
        for(int i=0;i<n;i++){
			cin >> ts[i].start >> ts[i].end;
        }
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(ts[j].end>ts[j+1].end) swap(ts[j],ts[j+1]);//冒泡排序所有的时间表
		}
    }
	int count=1;int endtime=0;
	for(int i=0;i<n;i++){
		if(ts[i].start>=ts[endtime].end){
			count++;//参加
			endtime=i;//最晚时间推迟
		}
	}
	cout << n-count << endl;
    }
    return 0;
}

```

~~这么一想我好像有好多东西接近ddl了~~

***

# 7-2

>**Drizzle** 面前有一条由一堆`非负整数`组成的道路，从第一个数字起步，每次他都能跳出不大于当前数字的距离，每个数字之间的距离为1，那么他最少需要跳多少次才能到达终点？
>
>### 要求:
>
>输入：第一行输入道路中数字的个数`n`也就是道路的长度，第二行输入这n个数字
>
>输出：输出一个数字，表示最少跳跃次数

这道题的贪心需要根据距离和跳跃长度进行判断，单方面考虑往数字大的跳会导致如 8 5 1 1 1 1 1 1 4 1 1 1 的结果出错，所以应该设定一个标准，两方面考虑一个点的最远距离。即当前位置到起点的距离+数字。

```C++
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int road[n];
	for (int i = 0; i < n; i++)
		cin >> road[i];
	int step = 1;
	int point = 0;
	while (point+road[point]<n-1)
	{
		int max_length = 0;
		int max_point = 1;
		for (int i = 1; i <= road[point] && i < n - point; i++)
		{
			if (i + road[point + i] > max_length)
			{
				max_length = i + road[point + i];
				max_point = i;
			}
		}
		step++;
		point += max_point;
	}
	cout << step << endl;
}
```

