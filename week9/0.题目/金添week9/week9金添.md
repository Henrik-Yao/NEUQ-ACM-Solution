# week9 ���
### ˫���� �߶θ���
����˼·�ǣ������趨һ���߶ν������������䶼���ǣ�Ȼ������������߶������ֵ�����Ƚ�ȥ����ϴ�ļ�����Ӷ�ת��Ϊһ���߶ν�ȡ���⡣
```C++
#include <bits/stdc++.h>
using namespace std;
int interval[100];//��¼����
int gap[100];//��¼����ļ��
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>interval[i];
    }
    sort(interval,interval+n);//�����䳤�ȴ�С��������
    int len=interval[n-1]-(interval[0]-1);//����һ���߶ν���������ȫ���ǣ�Ȼ���ټ�ȥ��ļ�����ɣ�
    for(int i=0;i<n-1;i++)
    {
        gap[i]=interval[i+1]-(interval[i]+1);//����ÿ��������֮��ļ��
    }    
    sort(gap,gap+n-1,cmp);//���������Ӵ�С����
    for(int i=0;i<=m-2;i++)//�����ܵ�ɾȥ������
    {
        len-=gap[i];
    }
    cout<<len;
    return 0;  
}
```
### week 9 ���񸲸�
����ĵݹ����⣬���ȿ��Ǹ�����Ϊn����������n-1,n-2,n-3����ʱ���ν��еݹ�.
```C++
#include <bits/stdc++.h>
using namespace std;
long long a[51];
long long ans(long long n)//����ݹ�����
{
    if(a[n])
    return a[n];
    else if(n==1)
    return a[1]=1;
    else if(n==2)
    return a[2]=2;
    else if(n==3)
    return a[3]=4;
    else
    return a[n]=ans(n-1)+ans(n-2)+ans(n-3);
}
int main()
{
    long long n;
    while(cin>>n)
    {
        cout<<ans(n)<<endl;
    }
    return 0;
}
```






