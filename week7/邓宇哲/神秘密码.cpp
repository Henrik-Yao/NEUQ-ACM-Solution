#include <iostream>
using namespace std;
string bds(string);
string xiang(string);
int point = 0;
int lengths;
string outcome;
main()
{
    string compressed;
    cin >> compressed;
    lengths = compressed.length();
    cout << bds(compressed);
}
string bds(string a)
{
    string result;//储存表达式的返回值的变量
    result += xiang(a);//获得当前的项
    while (point < lengths)//防止越界
    {
        while (((a[point] >= 'a' && a[point] <= 'z') || (a[point] >= 'A' && a[point] <= 'Z')))//普通字母直接保存
        {
            result += a[point++];
        }
        if (a[point] == '[')//项的开端，求项
        {
            result += xiang(a);
        }
        if (a[point] == ']')//项的结束，退出求表达式
        {
            point++;
            break;
        }
    }
    return result;
}
string xiang(string a)
{
    if (a[point] == '[')
    {
        point++;
        int num = 0;//记录重复次数的变量
        while (a[point] >= '0' && a[point] <= '9')
        {
            num = num * 10 + a[point] - '0';
            point++;
        }
        string cache = bds(a);//表达式储存到缓存
        string result;
        for (int i = 0; i < num; i++)
        {
            result += cache;//反复加表达式
        }
        return result;
    }
    return "";//不是项，返回空值
}