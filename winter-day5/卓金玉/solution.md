# 寒假集训—day5(查找)
## 7-1 相邻数对
### 思路
数据输入set后从前到后找相差1 的元素输出即可

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> s;
    int num, cnt = 0;
    while (n--)
    {
        cin >> num;
        s.insert(num);
    }
    auto it = s.begin();
    auto itt = ++s.begin();
    int a, b;
    for (it, itt; itt != s.end(); ++itt, ++it)
    {
        a = *it;
        b = *itt;
        // cout << "a = " << a << " "
        //      << "b = " << b << endl;
        if (b - a == 1)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
```
## 7-3 两个有序序列的中位数
### 思路
利用stl的排序，再输出下标即可

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    list<int> l;
    int num;
    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> num;
        l.push_back(num);
    }
    l.sort();
    auto it = l.begin();
    int i = 0;
    while (i != ceil((2 * n + 1) / 2) - 1)
    {
        it++;
        i++;
    }
    cout << *it << endl;
    return 0;
}
```

## 7-4 二分查找
### 思路
just二分查找，只定义一个二分查找的函数即可
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int biosearch(int x, int l, int r, int a[])
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    if (x == a[mid])
    {
        cnt++;
        return mid;
    }
    else if (x < a[mid])
    {
        cnt++;
        return biosearch(x, l, mid - 1, a);
    }
    else
    {
        cnt++;
        return biosearch(x, mid + 1, r, a);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int re = biosearch(x, 0, n - 1, a);
    if (re == -1)
    {
        cout << -1 << endl
             << cnt << endl;
    }
    else
    {
        cout << re << endl
             << cnt << endl;
    }
    return 0;
}
```


## 7-5 冰岛人
### 思路
样例对了但wa了，很费解，模拟得好费劲，最后还是cv了一个代码
### 代码
```c++
// #include <bits/stdc++.h>
// using namespace std;
// #define N 100005
// typedef struct Lover
// {
//     string xing;
//     char gender;
//     int vis = 0;
// } LOVER;
// map<string, LOVER> mp;

// bool Inquire(string inquirema, string inquiremb, int depth)
// {
//     depth++;
//     // if (inquireida == -1 || inquireidb == -1)
//     // {
//     //     return 1;
//     // }
//     LOVER tmpa = mp[inquirema], tmpb = mp[inquiremb];
//     if (mp[tmpa.xing].vis == 0 && mp[tmpb.xing].vis == 0 && tmpb.xing != tmpa.xing)
//     {
//         mp[tmpa.xing].vis = depth;
//         mp[tmpb.xing].vis = depth;
//         return Inquire(tmpa.xing, tmpb.xing, depth);
//     }
//     else if (mp[tmpa.xing].vis == 0 && mp[tmpb.xing].vis == 0 && tmpb.xing == tmpa.xing)
//     {
//         return depth < 5 ? 0 : 1;
//     }
//     else if (mp[tmpa.xing].vis != 0 && mp[tmpa.xing].vis < 5)
//     {
//         return 0;
//     }
//     else if (mp[tmpb.xing].vis != 0 && mp[tmpb.xing].vis < 5)
//     {
//         return 0;
//     }
//     else if (mp[tmpa.xing].vis > 5)
//     {
//         return 1;
//     }
//     else if (mp[tmpb.xing].vis > 5)
//     {
//         return 1;
//     }
// }
// void reinit()
// {
//     for (auto it = mp.begin(); it != mp.end(); ++it)
//     {
//         it->second.vis = 0;
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int allovers, inquirenum;
//     string inquirexa, inquirexb, inquirema, inquiremb;
//     string m, x;
//     LOVER temp;
//     cin >> allovers;
//     for (int i = 0; i < allovers; ++i)
//     {
//         cin >> m >> x;
//         temp.xing = x;
//         if (x[x.length() - 1] == 'm')
//         {
//             temp.gender = 'm';
//             temp.xing = x.substr(0, x.length() - 1);
//         }
//         else if (x[x.length() - 1] == 'f')
//         {
//             temp.gender = 'f';
//             temp.xing = x.substr(0, x.length() - 1);
//         }
//         else if (x[x.length() - 1] == 'n')
//         {
//             temp.gender = 'm';
//             temp.xing = x.substr(0, x.length() - 4);
//         }
//         else
//         {
//             temp.gender = 'f';
//             temp.xing = x.substr(0, x.length() - 7);
//         }
//         mp[m] = temp;
//         // cout << "----test " << i + 1 << " ----" << endl;
//         // cout << i << "  " << temp.gender << "  " << temp.xing << endl
//         //      << "----test " << i + 1 << " end----" << endl;

//         // //  输入正常
//     }
//     cin >> inquirenum;
//     while (inquirenum--)
//     {
//         cin >> inquirema >> inquirexa >> inquiremb >> inquirexb;

//         if (mp.find(inquirema) == mp.end() || mp.find(inquiremb) == mp.end())
//         {
//             cout << "NA" << endl;
//             //             continue;
//         }
//         else if (mp[inquirema].gender == mp[inquiremb].gender)
//         {
//             cout << "Whatever" << endl;
//             //             continue;
//         }
//         else if (!Inquire(inquirema, inquiremb, 1))
//         {
//             cout << "No" << endl;
//         }
//         else
//         {
//             cout << "Yes" << endl;
//         }
//         reinit();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
#define MAX 100005
int N, M;
int sex[MAX];
string f[MAX], s[MAX];
bool vis[MAX];
int father[MAX];
string get(string str, int p)
{
    int pos;
    if (p == 1)
        pos = str.rfind("sson");
    else
        pos = str.rfind("sdottir");
    return str.substr(0, pos);
}
void init()
{
    for (int i = 1; i <= N; ++i)
        father[i] = -1;
}
bool judge(int l, int r)
{
    memset(vis, false, sizeof(vis));
    set<int> stl, str;
    int Count = 1;
    int k = l;
    while (k != -1)
    {
        vis[k] = true;
        if (Count < 5)
            stl.insert(k);
        if (k == r)
            return false;
        k = father[k];
        Count++;
    }
    k = r;
    Count = 1;
    while (k != -1)
    {
        if (Count < 5)
            str.insert(k);
        if (vis[k])
        {
            if (stl.count(k) || str.count(k))
                return false;
        }
        k = father[k];
        Count++;
    }
    return true;
}
int main(void)
{
    cin >> N;
    init();
    for (int i = 1; i <= N; ++i)
    {
        cin >> f[i] >> s[i];
        mp[f[i]] = i;
        int len = s[i].length();
        if (s[i][len - 1] == 'n')
            sex[i] = 1;
        else if (s[i][len - 1] == 'r')
            sex[i] = 0;
        else if (s[i][len - 1] == 'm')
            sex[i] = 1;
        else
            sex[i] = 0;
    }
    for (int i = 1; i <= N; ++i)
    {
        int len = s[i].length();
        if (s[i][len - 1] == 'n')
        {
            string fs = get(s[i], 1);
            int fp = mp[fs];
            father[i] = fp;
        }
        else if (s[i][len - 1] == 'r')
        {
            string fs = get(s[i], 0);
            int fp = mp[fs];
            father[i] = fp;
        }
    }
    cin >> M;
    string lf, ls, rf, rs;
    for (int i = 1; i <= M; ++i)
    {
        cin >> lf >> ls >> rf >> rs;
        if (!mp.count(lf) || !mp.count(rf))
            cout << "NA" << endl;
        else
        {
            int lp = mp[lf], rp = mp[rf];
            if (sex[lp] == sex[rp])
                cout << "Whatever" << endl;
            else
            {
                if (judge(lp, rp))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
    return 0;
}
```

## 7-6 二分查找
### 思路
利用set排序并查找，再用一个int存下标
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
// int a[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, quest;
    set<int> s;
    int num;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            s.insert(num);
        }
        // int i = 0;
        // memset(a, 0, sizeof(a));
        map<int, int> m;
        int i = 1;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            // a[i] = *it;
            // i++;
            if (it == s.begin())
            {
                cout << *it;
            }
            else
            {
                cout << " " << *it;
            }
            m[*it] = i;
            i++;
        }
        cout << endl;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            cin >> quest;
            auto it = m.find(quest);
            if (it != m.end())
            {
                if (i == 0)
                    cout << it->second;
                else
                    cout << " " << it->second;
            }
            else
            {
                if (i == 0)
                    cout << "0";
                else
                    cout << " 0";
            }
        }
        cout << endl;
        s.clear();
    }

    return 0;
}
```
## 7-7 愤怒的牛
### 思路
二分答案，比较好写，原理和二分查找相同
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n, m;
#define N 100005
int a[N];
bool quest(int mid)
{
    int cnt = 1;
    int pos = a[0] + mid;
    for (int i = 0; i < n; ++i)
    {
        if (pos <= a[i])
        {
            cnt++;
            pos = a[i] + mid;
        }
    }
    return m <= cnt ? 1 : 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int mid = 0, l = 0, r = a[n - 1] - a[0];
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (quest(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l-1;
    return 0;
}
```