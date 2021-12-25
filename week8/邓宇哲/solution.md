# 最少失约
这题没用贪心算法，而使用深度优先搜索，因为不确保能找到最优解。  
声明date类，保存会议的开始时间，结束时间，结束后可参加会议的数量，结束后可参加的会议的编号。企图用搜索的深度来表示参加会议的数量。
```c++
#include <algorithm>
#include <iostream>
using namespace std;
class date
{
public:
	int start, end, num = 0;
	int next[128] = {0};
};
bool compare(date a, date b)//自定义排序的函数
{
	return a.start < b.start;
}
void dfs(date *, int);
int deep = 1;//保存当前搜索深度的变量
int maxt;//保存最大搜索深度的变量
main()
{
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		maxt = 0;
		date node[t];
		for (int j = 0; j < t; j++)//输入
		{
			cin >> node[j].start >> node[j].end;
		}
		sort(node, node + t, compare);//重要，按开始时间进行编号排序
		for (int j = 0; j < t - 1; j++)//遍历所有会议，对每个会议添加 ‘结束后能参加的会议’ 的信息
		{
			for (int k = j + 1; k < t; k++)
			{
				if (node[k].start >= node[j].end)
				{
					node[j].next[node[j].num++] = k;
				}
			}
		}
		for (int j = 0; j < t; j++)//对每个会议进行搜索遍历，求出最大搜索深度
		{
			dfs(node, j);
		}
		cout << t-maxt<<endl;
	}
}
void dfs(date *node, int n)
{
	maxt = max(maxt, deep);
	{
		for (int i = 0; i < node[n].num; i++)//对每个会议‘结束后能参加的会议’进行搜索，记录深度
		{
			deep++;
			dfs(node, node[n].next[i]);
			deep--;
		}
	}
}
```
# 跳一跳
这题深度优先会裂开，只能贪心了。
比较’下一步能走到的点能到达的最远位置‘，进行合适的点选择。
```c++
#include <iostream>
using namespace std;
main()
{
    long n, step = 0;
    long long maxt;//记录最优的位移量
    cin >> n;
    long long *list = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    long point = 0;
    bool sign=0;
    while (point < n - 1)
    {
        maxt =0;
        step++;
        for (long i = point + 1; (i <= point + list[point]) && i < n; i++)
        {   
            if(list[point]+point>=n-1)//没有这个判读直接超时！！！
            {
                sign = 1;
                break;
            }
            if(list[i] + i>=list[maxt+point]+point+maxt)
            {
                maxt = i-point;
            }
        }
        if(sign==1)
        {
            break;
        }
        point += maxt;
        
    }
    cout << step ;
    delete[] list;//别忘了删除
}
```