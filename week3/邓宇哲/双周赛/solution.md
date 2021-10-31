# 最大子段和
为了减少时间复杂度，我们必须采用分治的算法。把数组分为两段，分别计算左段的最大子段和，右端的最大子段和。再计算跨越两端的最大子段和，选取其中最大的作为数组的最大子段和。
```c++
#include <iostream>
using namespace std;
int zdh( int a[], int, int);
main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << zdh(a, 0, n - 1);
}
int zdh( int a[], int s, int e)
{
    if (s == e)
    {
        return a[s];
    }
    int m = (e + s) / 2;
    int sum1 = zdh(a, s, m);
    int sum2 = zdh(a, m+1 , e);
    int cache = 0, lmax = 0, rmax = 0;
    for (int i = m; i >= s; i--)
    {
        cache += a[i];
        lmax = max(lmax, cache);
    }
    cache = 0;
    for (int i = m+1; i <= e; i++)
    {
        cache += a[i];
        rmax = max(rmax, cache);
    }
    int sum3 = lmax + rmax;
    return max(max(sum1, sum3),sum2);
}

```
# 汉诺塔问题
简单的递归，之前已经分析过了。
```c++
#include <iostream>
using namespace std;
void hannuota(int, string, string, string);
main()
{
    string a, b, c;
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    hannuota(n, a, b, c);
}
void hannuota(int n, string a, string b, string c)
{
    if (n == 1)
    {
        cout << a << "->" << c << endl;
        return;
    }
    hannuota(n - 1, a, c, b);
    cout << a << "->" << c<<endl;
    hannuota(n - 1, b, a, c);
    return;
}
```
# 汉诺塔III
找规律 a[i] = a[i - 1] * 3 + 2
~~~c++
#include <iostream>
using namespace std;
long long sum=0;
void hannuota(int);
main()
{
    int n;
    while (cin>>n)
    {
        long long a[n];
        a[0] = 2;
        for (int i = 1; i < n;i++)
        {
            a[i] = a[i - 1] * 3 + 2;
        }
        cout << a[n - 1]<<endl;
    }
}
~~~
# 汉诺塔II
数学找规律
~~~c++
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
main()
{
    double a[100];
    memset(a, 9999999, sizeof(a));
    int n;
    while (cin >> n)
    {
        a[0] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int p = 0; p < i; p++)
                a[i] = min(a[i], a[p] * 2 + pow(2,i-p)-1);
        }
        cout << a[n - 1] << endl;
    }
}
~~~
# 简单的归并
对于两个有序数组，定义两个指针a,b，如果a指针所指向的数小于b的，则输出a指向的数，保持b不动，将a右移一位。反之亦然。
~~~C++
#include <iostream>
using namespace std;
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n1;
        cin >> n1;
        int a[n1];
        for (int p = 0; p < n1; p++)
        {
            cin >> a[p];
        }
        int n2;
        cin >> n2;
        int b[n2];
        for (int p = 0; p < n2; p++)
        {
            cin >> b[p];
        }
        int j = 0, k = 0, out[n1 + n2];
        for (int p = 0; p < n1 + n2;p++)
        {
            if (a[j] > b[k])
            {
                out[p] = b[k];
                k++;
            }
            else {
                out[p] = a[j];
                j++;
            }

        }
        for (int p = 0; p < n1 + n2-1;p++ )
        {
            cout << out[p] << ' ';
        }
        cout << out[n1 + n2 - 1] << endl;
    }
}
~~~
# 字符串的全排列
可以使用深度优先搜索，但是我还不会。只能用next_permutation()这个是真的骚。
~~~c++
#include <algorithm>
#include <iostream>
using namespace std;
main()
{
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    int l = a.length(), sum = 1;
    for (int i = 1; i <= l; i++)
    {
        sum *= i;
    }
    for (int i = 0; i < sum; i++)
    {

        cout << a << endl;
        next_permutation(a.begin(), a.end());
    }
}
~~~
# 逆序对
对原来的分治归并排序进行改动，
~~~c++
#include <iostream>
using namespace std;
long long sum = 0;
void guibing(long long a[], long long s, long long m, long long e, long long cache[])
{
    long long p = 0;
    long long i = s, j = m + 1;
    while (i <= m && j <= e)
    {
        if (a[i] > a[j])//改变了这个符号，使它由大到小排列。
        {
            sum += e - j + 1;//另外增加这一行，每执行此判断语句都可以加上此数对应的逆序数。
            cache[p++] = a[i++];
        }
        else
        {
            cache[p++] = a[j++];
        }
    }
    while (i <= m)
    {
        cache[p++] = a[i++];
    }
    while (j <= e)
    {
        cache[p++] = a[j++];
    }
    for (long long i = 0; i < e - s + 1; i++)
    {
        a[s + i] = cache[i];
    }
}
void fenzhipaixu(long long a[], long long s, long long e, long long cache[])
{
    if (s < e)
    {
        long long m = s + (e - s) / 2;
        fenzhipaixu(a, s, m, cache);
        fenzhipaixu(a, m + 1, e, cache);
        guibing(a, s, m, e, cache);
    }
}
long long cache[1000009];
main()
{
    long long n;
    cin >> n;
    long long a[n+10];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fenzhipaixu(a, 0, n - 1, cache);
    cout << sum;
}
~~~
# 二分查找
我在你输入的时候就给你找出来了hhh。
```c++
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long a, b,c=0;
    cin >> a >> b;
    for (long i = 0; i < a;i++)
    {
        long num;
        cin >> num;
        if(num>=b&&c==0)
        {
            cout << ++i<<endl;
            c=1;
        }
    }
    if(c==0)
    {
        cout << a + 1<<endl;
    }
}
```
