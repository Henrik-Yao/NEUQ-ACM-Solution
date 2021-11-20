#include <iostream>
using namespace std;
void get_Next(string target, int tl, int *Next) //求出Next数组
{                                               //Next数组是从 target[0到i-1]前子串 的前缀后缀最大值
    int point1 = 0, point2;
    Next[0] = point2 = -1;                                    //next数组首位默认为-1
    while (point1 < tl)                                       //边界条件
        if (point2 == -1 || target[point1] == target[point2]) //类似于KMP的匹配
            Next[++point1] = ++point2;
        else
            point2 = Next[point2]; //失配
}
int KMP(string origin, string target, int ol, int tl)
{
    int Next[tl], sum = 0;
    get_Next(target, tl, Next); //获得next数组
    int point1 = 0, point2 = 0; //从0位开始匹配
    while (point1 < ol)         //临界值
    {
        if (point2 == -1 || origin[point1] == target[point2]) //相应字符匹配成功，继续
            point1++, point2++;
        else
            point2 = Next[point2]; //失配
        if (point2 == tl)
            sum++, point2 = Next[point2]; //point2==tl时，全字符串匹配成功，sum+1，point2置为Next[point2]继续开始新一轮匹配
    }
    return sum; //返回
}
int main()
{
    string origin, target;
    cin >> origin >> target;
    int ol = origin.length(), tl = target.length();
    cout << KMP(origin, target, ol, tl);
    return 0;
}