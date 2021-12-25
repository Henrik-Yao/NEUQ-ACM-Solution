#include<bits/stdc++.h>
using namespace std;
int a[1000005];//记录每一格的步数
//提示：要比较到达该点的距离+该点所能到达的最远距离才能得出最优解
int main()
{
    int n,x,s=1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int i = 1;
    while(i + a[i] < n)
    {
        x = 0; x = 0;
        for (int j = 1; j <= a[i]; j++)//遍历找能跳最远处的点
        {
            if(j==1) x = 1;//初始化
            if (j+a[i + j] > x+a[i + x]) x = j;//标记能跳最远的点
        }
        i += x;//跳到该位置
        s++;//跳下一位
    }
    cout << s;
    return 0;
}

