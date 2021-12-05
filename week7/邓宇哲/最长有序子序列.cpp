#include <cstring>
#include <iostream>
using namespace std;
int indexff[1111]={0};int datass[1111]={0};
main()
{
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int lelele = -10;//随便定义的要输出的变量
        if (i != 0)//题目要求
        {
            cout << '\n';
        }
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++)//输入
        {
            cin >> datass[j];
            indexff[j] = 1;
        }
        for (int j = 1; j <= n;j++)//遍历
        {
            for (int k = 1; k <= j;k++)
            {
                if(datass[k]<datass[j])
                {
                    indexff[j] = max(indexff[j], indexff[k] + 1);
                }
            }
        }
        for (int j = 1; j <= n;j++)
        {
            lelele = max(lelele, indexff[j]);//找最大值。
        }
        cout << lelele<<endl;
    }
}