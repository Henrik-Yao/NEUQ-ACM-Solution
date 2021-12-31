# ���һ�����
### 7-1 ��������
�򵥵Ĳ���������֪ԭ����
```C++
#include <bits/stdc++.h>
using namespace std;
//�������򣬴�ӡ·��
int main()
{
    int a[1000];
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
                int remp = a[i];
                for (k = i - 1; k > j; k--)
                    a[k + 1] = a[k];
                a[k + 1] = remp;
            }
            for (int i = 0; i < num - 1; i++)
                cout << a[i] << " ";
            cout << a[num - 1] << endl;
        }
    }

    return 0;
}
```
### 7-2 �ɼ�����
�ṹ�����򣬶���sort���򼴿�
```C++
#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int num;
};
bool cmp(stu a,stu b)
{
    if(a.num!=b.num)
    return a.num>b.num;
    else
    return a.name<b.name;
}
int main()
{
    int n;
    cin>>n;
    stu p[100];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].name>>p[i].num;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<p[i].name<<" "<<p[i].num<<endl;
    }
    return 0;
}
```
### 7-3 ��������
����һ�����飬��¼ÿ�����ֳ��ֵĴ�������
```C++
#include <bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int remp;
        cin>>remp;
        a[remp]++;
    }
    for(int i=0;i<100;i++)
    {
        if(a[i])
        cout<<i<<":"<<a[i]<<endl;
    }


    return 0;
}
```
### 7-6 ��������
������ԣ��ɿ����ù鲢�������⡣
```C++
#include <iostream>
using namespace std;
int a[1000000], c[1000000];
long long ans=0;
void mergesort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	int k = 0;
	int i = left, j = mid + 1;
	while (i <= mid&&j<=right) {
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++] , ans += mid - i + 1;
	}
	while (j <= right)
			c[k++] = a[j++];
	while (i <= mid)
			c[k++] = a[i++];
	for (i = left, j = 0; i <= right; i++, j++)
	{
		a[i] = c[j];
	}
}   
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(a, 0, n - 1);
	// for (int i = 0; i < n; i++)
	// 	cout << a[i];
    cout<<ans;
	return 0;
}


```
