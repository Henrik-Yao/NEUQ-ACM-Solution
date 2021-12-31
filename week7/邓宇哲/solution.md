# 7-1 词典
这不就是map的定义吗？
```c++
#include <iostream>
#include <map>
using namespace std;
map<string, string> dic;
main()
{
    int n, m;
    string origin, target;
    string wanted;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        cin >> target >> origin;
        dic[origin] = target;
    }
    for (int i = 0; i < m;i++)
    {
        cin >> wanted;
        if(dic.find(wanted)==dic.end())
        {
            cout << "eh" << endl;
            continue;
        }
        cout << dic[wanted] << endl;
    }
}
```
# 7-2 神秘密码
这题和递归一样的，首先分析成分。  
这里我把它分析成 ‘表达式’ 和 ‘项’ 这两种成分。表达式由 ‘字母’ 和 ‘项’ 组成，项以 [数字+表达式] 的形式存在。这就形成了一种递归。
```c++
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
```
# 7-3 删除公用字符
可用map可用set。但是这更倾向于set的定义。但是我还是用map写。  getline()也可以返回布尔值。  
别忘了最后要清空保存字符的set或map！！！
```c++
#include <iostream>
#include <map>
using namespace std;
map<char, bool> chars;
main()
{
    string origin, target;
    while (getline(cin, origin) && getline(cin, target))
    {
        int ol = origin.length();
        int tl = target.length();
        for (int i = 0; i < tl; i++)
        {
            chars[target[i]] = 1;
        }
        for (int i = 0; i < ol; i++)
        {
            char ch = origin[i];
            if (chars[origin[i]])
                continue;
            cout << origin[i];
        }
        cout << endl;
        chars.clear();
    }
}
```
# 7-4 最长有序子序列
这题再次提醒我们认真看题。  
首先indexff记录之前最长上升子序列的大小。datass记录数据。  

```c++
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
```
# 7-5 背包问题
不定次数的一定要有while  

```c++
#include <iostream>
using namespace std;
main()
{
    int n, c;
    while(cin>>n>>c)
    {
        int weight[n] = {0}, value[n] = {0}, sum[n*n] = {0};//sum是储存临时数据的数组
        for (int i = 0; i < n;i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n;i++)
        {
            cin >> value[i];
        }
        for (int i = 0; i < n;i++)//遍历所有情况
        {
            for (int k = c; k >= weight[i];k--)
            {
                sum[k] = max(sum[k], sum[k - weight[i]] + value[i]);
            }
        }
        cout << sum[c] << endl;
    }
}
```