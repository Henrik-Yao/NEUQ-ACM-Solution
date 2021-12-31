## **7-1 直接插入排序**

简单的直接插入排序

~~~#include <iostream>
using namespace std;
int a[1000];
int main()
{
   
    int num;
    while (cin >> num)
    {
        for (int i = 0; i < num; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < num; i++)
        {
            int j, k;
            for (j = i - 1; j >= 0; j--)
                if (a[j] < a[i])
                    break;
            if (j != i - 1)
            {
                int lsz = a[i];
                for (k = i - 1; k > j; k--)
                    a[k + 1] = a[k];
                a[k + 1] = lsz;
            }
            for (int i = 0; i < num - 1; i++)
                cout << a[i] << " ";
            cout << a[num - 1] << endl;
        }
    }
    return 0;
}
~~~



## **7-2 成绩排序**

结构体sort

~~~#include <iostream>
#include<algorithm>
using namespace std;
struct student
{
    string name;
    int num;
};
bool cmp(student a, student b)
{
    if (a.num != b.num)
        return a.num > b.num;
    else
        return a.name < b.name;
}
int main()
{
    int n;
    cin >> n;
    student lsz[100];
    for (int i = 0; i < n; i++)
    {
        cin >> lsz[i].name >> lsz[i].num;
    }
    sort(lsz, lsz + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << lsz[i].name << " " << lsz[i].num << endl;
    }
    return 0;
}
~~~



## **7-3 统计工龄**

统计数字出现次数

~~~#include <iostream>
#include<algorithm>
using namespace std;
int a[100];
int main()
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int lsz;
        cin >> lsz;
        a[lsz]++;
    }
    for (int i = 0; i < 100; i++)
    {
        if (a[i])
            cout << i << ":" << a[i] << endl;
    }
    return 0;
}
~~~



## **7-4 最接近神的人**

简易的归并

~~这道题我是不是在洛谷上见过。。。~~

~~~#include <iostream>
#include<algorithm>
#include <iostream>
using namespace std;
int a[1000000], c[1000000];
long long ans = 0;
void gb(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	gb(a, left, mid);
	gb(a, mid + 1, right);
	int k = 0;
	int i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++], ans = ans + mid - i + 1;
	}
	while (j <= right)
		c[k++] = a[j++];
	while (i <= mid)
		c[k++] = a[i++];
	for (i = left, j = 0; i <= right; i++, j++)
		a[i] = c[j];
	
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	gb(a, 0, n - 1);
	cout << ans;
	return 0;
}
~~~



## **7-5 堆排序**

不会，参考https://blog.csdn.net/m0_51495585/article/details/118147395



## 7-6 快速排序

基础的快排

~~~#include <iostream>
#include<algorithm>
#include <iostream>
using namespace std;
int a[1000];
int num;
void qsor(int left, int right)
{
    if (left >= right)
        return; //直接退出
    int key = a[left];
    int l = left;
    int r = right;
    while (l < r)
    {
        while (a[r] >= key && l < r)
            r--;
        while (a[l] <= key && l < r)
            l++;
        if (r > l)
            swap(a[l], a[r]);
    }
    swap(a[l], a[left]);
    qsor(left, l - 1);
    qsor(l + 1, right);
}
int main()
{
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> a[i];
    qsor(0, num - 1);
    for (int i = 0; i < num; i++)
        cout << a[i] << endl;
    return 0;
}
~~~





注：因为没注意结束时间，所有代码均未经历数据检验，可能存在问题

~~明明说好第二天晚上交为什么第二天早八就关了啊啊啊啊~~

