#include <iostream>
using namespace std;
int yueshu(int, int);
int fenpingguo(int);
main()
{
    int n;
    cin >> n;
    cout << fenpingguo(n);
}
int yueshu(int n, int a[])//传入一个数和数组，将约数存入数组，返回约数的个数
{
    int t = 0;
    for (int i = 1; i < (n + 1) / 2+1; i++)
    {
        if (n % i == 0)
        {
            a[t] = i;
            t++;
        }
    }
    return t;
}
int fenpingguo(int n)
{
    int A[1000] = {0};
    A[1] = 1;
    A[2] = 2;
    A[3] = 2;
    A[4] = 4;
    A[5] = 2;
    A[6] = 6;
    int zhishu[1000]={0};//全是零的初始化数组
    for (int i = 3; i < 1000;i++)
    {
        int b = 1;
        for (int y = 2; y < i;y++)
        {
            if (i%y==0)//确认是不是质数
            {
                b = 0;
                break;
            }
        }
        if (b==1)
        {
            zhishu[i] = i;//如果是质数，对应编号存放
        }
    }
    zhishu[2] = 2;//上述质数算法无法查出2，故单独赋值
    for (int i = 5; i < 1000;i++)
    {
        if(zhishu[i]!=0)
        {
            A[i] = 2;//凡是质数只有两种情况
        }
    }
    for (int i = 7; i < 1000; i++)//将结果储存于数组
    {
        if(A[i]!=2)
        {
            int b[1000] = {0};
            int p = yueshu(i, b);
            for (int t = 0; t < p; t++)
            {
                A[i] = A[i] + A[b[t]];
            }
            A[i] += 1;
        }
    }
    return A[n];//输出需要的值
}
