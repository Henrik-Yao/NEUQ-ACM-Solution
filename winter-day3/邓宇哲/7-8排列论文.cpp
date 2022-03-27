#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
int howMuchBefore[1000];
deque<int> dict[1000];//节点名称对子节点的索引
deque<int> outcome; //保存结果
deque<int> list;   //队列
main()
{
    int n, m;
    while (cin >> n >> m)
    {
        bool sign = 0; //是否有多种结果
        int num = 0;  // 起点的数量
        for (int i = 1; i <= m; i++)
        {
            int d, u;
            cin >> d >> u;
            dict[d].push_back(u); //给节点d添加一个子节点u
            howMuchBefore[u]++;     //在u前面的论文个数增加
        }
        for (int i = 1; i <= n; i++)
        {
            if (howMuchBefore[i] == 0)//拓扑排序，先找出所有起点
            {              
                list.push_back(i); //找到就加入队列
                num++;
            }
        }
        if (num > 1) //起点太多，排序肯定不唯一
            sign = 1;
        while (!list.empty())
        {
            int p = list.front();//取队列中最前面的元素为p
            list.pop_front();//删去队列中最前的元素
            outcome.push_back(p);//添加到排序队列中去
            for (int i = 0; i < dict[p].size(); i++)//遍历p的子节点
            {
                int y = dict[p][i];
                howMuchBefore[y]--;//告诉这些子节点，在你们之前的元素减少一个
                if (!howMuchBefore[y])//如果y的前面没有元素了，只能直接将y放入队列
                {
                    list.push_back(y);
                }
            }
        }
        if (outcome.size() == n) //可以进行拓扑排序
        {
            if (!sign)
                cout << "1" << endl;
            else
                cout << "2" << endl;
        }
        else
            cout << "0" << endl;    //不能拓扑排序
        for (int i = 0; i < m; i++) //清空操作
            dict[i].clear();
        outcome.clear();
        while (!list.empty())
            list.pop_front();
        memset(howMuchBefore, 0, sizeof(howMuchBefore));
    }
}