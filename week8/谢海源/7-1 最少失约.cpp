#include<bits/stdc++.h>
using namespace std;
struct act//活动的安排
{
    int sta; int end;
}a[105];
bool cmp(act a,act b)
{
    return a.end < b.end; //按结束时间从小到大排列
}
int main()
{
    int t,n,maxa;
    cin >> t;
    while (t--)
    {
        maxa = 0;
        cin >> n;
        for (int i = 0; i < n;i++)//输入
        {
            cin >> a[i].sta >> a[i].end;//从sta点到end点
        }
        sort(a, a + n, cmp);//排序
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].sta < x) continue;//去掉冲突的
            maxa++;
            x = a[i].end;
        }
        cout <<n-maxa<<endl;
        /*for (int i = 0; i < n; i++)//输入
        {
            cout<< a[i].sta <<" "<< a[i].end << endl;
        }*/
    }
    return 0;
}

