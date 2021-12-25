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
