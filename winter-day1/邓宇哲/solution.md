# 字符串对称
依题意得，将字符串的一半进行入栈，然后用另一边匹配进行出栈，最后判断是否还留有元素。
~~~c++
#include <deque>
#include <iostream>
using namespace std;
main()
{
    string a;
    deque<char> z;
    getline(cin, a);
    for (int i = 0; i < (a.length() + 1) / 2; i++)
    {
        z.push_back(a[i]);
    }
    for (int i = (a.length() + 1) / 2; i < a.length(); i++)
    {
        if (a[i] == *z.rbegin())
        {
            z.pop_back();
        }
    }
    if (z.size() != 0)
    {
        cout << "no";
    }
    else
        cout << "yes";
}
~~~
# 小明打字
使用deque实现简单的操作。特别要注意对边缘条件的判断。
~~~c++
#include <deque>
#include <iostream>
using namespace std;
bool func = true;
main()
{
    deque<char> outcome;
    int point1 = 0;
    deque<char>::iterator point;
    string raw;
    getline(cin, raw);
    for (int i = 0; i < raw.length(); i++)
    {
        point = outcome.begin();
        if (raw[i] == '{')
        {
            if (point1 != 0)
            {
                point1--;
            }
        }
        else if (raw[i] == '}')
        {
            if (point1 < outcome.size())
            {
                point1++;
            }
        }
        else if (raw[i] == '[')
        {
            point1 = 0;
        }
        else if (raw[i] == ']')
        {
            if (outcome.size() != 0)
            {
                point1 = outcome.size();
            }
        }
        else if (raw[i] == '-')
        {
            func = !func;
        }
        else if (raw[i] == '=')
        {
            point += point1;
            outcome.erase(--point);
            point1--;
        }
        else
        {
            point += point1;
            if (func == true)
            {
                if (point != outcome.end())
                {
                    outcome.insert(point, raw[i]);
                }
                else
                    outcome.push_back(raw[i]);
            }
            else
            {
                if (point != outcome.end())
                {
                    *point = raw[i];
                }
                else
                    outcome.push_back(raw[i]);
            }
            point1++;
        }
    }
    for (deque<char>::iterator i = outcome.begin(); i != outcome.end(); i++)
    {
        cout << *i;
    }
}

~~~
# 特殊约瑟夫问题
模拟题，要仔细观察规律，使用周期来解决问题。注意题目所给的条件。
~~~c++
#include <deque>
#include <iostream>
using namespace std;
main()
{
    int N, M, K;
    deque<int> list;
    int point1 = 0;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        list.push_back(i);
    }
    deque<int>::iterator point = list.begin();
    for (int i = N; i > 0; i--)
    {
        point = list.begin();
        if ((N - i) % 2) //顺时针
        {
            point1 = (K + point1) % i - 1;
            if (point1 < 0)
            {
                point1 = list.size() - 1;
            }
            point += point1;
            if (point1 >= i)
            {
                point1 -= i;
            }
        }
        else //逆时针
        {
            point1 = point1 - (M % i - 1);
            if (point1 < 0)
            {
                point1 += i;
            }
            point += point1;
            point1--;
            if(point1<0)
            {
                point1 += i-1;
            }
            if(point1>=i)
            {
                point -= i;
            }
        }
        cout << *point << ' ';
        list.erase(point);
    }
}

~~~
# 魔王语言解释
直接翻译，注意对迭代器的使用。
~~~c++
#include <deque>
#include <iostream>
using namespace std;
deque<char> list;
deque<char>::iterator it = list.begin();
void function(deque<char>&, int &);
main()
{
    string raw;
    getline(cin, raw);
    for (int i = 0; i < raw.length(); i++)
    {
        list.push_back(raw[i]);
    }

    for (int point = 0; point < list.size(); point++)
    {
        it = list.begin() + point;
        if (*it == 'B')
        {
            *it = ' t';
            list.insert(it + 1, 'A');
            it = list.begin() + point;
            list.insert(it + 2, 'd');
            it = list.begin() + point;
            list.insert(it + 3, 'A');
            it = list.begin() + point;
        }
        else if (*it == 'A')
        {
            *it = 's';
            list.insert(it + 1, 'a');
            it = list.begin() + point;
            list.insert(it + 2, 'e');
            it = list.begin() + point;
        }
        else if (*it == '(')
        {
            function(list, point);
        }
    }
    for (int i = 0; i < list.size()-1;i++)
    {
        cout << list[i];
    }
    cout<<endl;
}
void function(deque<char> &a, int &point)
{
    int endin;
    for (endin = point + 1; endin < a.size(); endin++)
    {
        if (a[endin] == ')')
        {
            break;
        }
    }
    int len = endin - point - 1;
    char cache[len];
    for (int i = 0; i < len; i++)
    {
        cache[i] = a[point + i + 1];
    }
    a[point] = a[point + 1];
    for (int i = 0; i < len - 1; i++)
    {
        list[++point] = cache[len - 1 - i];
        list.insert(list.begin()+(++point),cache[0]);
    }
    list.erase(list.begin() + (++point));
    list.erase(list.begin() + point--);
}
~~~
# 列车车厢重排
~~~c++
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
using namespace std;
class que
{
public:
    int a[1024];
    int length = 0;
};
main()
{
    int n, num = 0, pointmin = 0, pointmax = 0, point = 0;
    cin >> n;
    int queue[n];//保存原始数据的数组
    for (int i = 0; i < n; i++)
    {
        cin >> queue[i];
    }
    que p[128];//保存各个队列的数组
    map<int, int> mp;//为所查询到的最小值进行索引
    int minlist[128] = {};//保存每个队列末尾元素的数组，
    for (int i = 0; i < n; i++)
    {
        int maxs = 0;
        for (int j = 0; j < num; j++)//找出所有队列中最大的末尾元素
        {
            if (maxs < p[j].a[p[j].length - 1])
            {
                pointmax = j;
                maxs = p[j].a[p[j].length - 1];
            }
            minlist[j] = p[j].a[p[j].length - 1];//顺便取走末尾元素
            mp[p[j].a[p[j].length - 1]] = j;//创建为末尾元素索引
        }
        if (maxs < queue[i])//不得不开新的队列
        {
            point = num;
            p[point].a[p[point].length++] = queue[i];
            num++;
            continue;
        }
        sort(minlist, minlist + num);//排序
        for (int t = 0; t < num; t++)//找到合适的队列并插入
        {
            if (minlist[t] > queue[i])
            {
                point = mp[minlist[t]];//使用索引
                break;
            }
        }
        p[point].a[p[point].length++] = queue[i];//插入
    }

    for (int i = 0; i < p[0].length-1; i++)
    {
        cout << p[0].a[i] << ' ';
    }

    cout<<p[0].a[p[0].length-1] << endl;
    cout << num<<endl;
}

~~~
# 括号配对
出栈入栈
~~~c++
#include <deque>
#include <iostream>
using namespace std;
main()
{
    string a;
    deque<char> z;
    getline(cin, a);
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            z.push_back(a[i]);
        }
        else if (a[i] == ')' && *z.rbegin() == '(')
        {
            z.pop_back();
        }
        else if (a[i] == ']' && *z.rbegin() == '[')
        {
            z.pop_back();
        }
        else if (a[i] == '}' && *z.rbegin() == '{')
        {
            z.pop_back();
        }
    }
    if (z.size() !=0)
    {
        cout << "no";
    }
    else
        cout << "yes";
}
~~~