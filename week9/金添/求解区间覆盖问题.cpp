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



