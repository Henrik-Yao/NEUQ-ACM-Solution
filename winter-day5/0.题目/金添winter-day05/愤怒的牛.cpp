#include <bits/stdc++.h>
using namespace std;
//̰��+����
//˼·�����ö��ְѼ������п��ܵĴ��г�����ͨ��̰���жϸ�ֵ�Ƿ��������⣬��ͨ������������
int cnt;//��ʱ���˶���ţ
int map1[100000]; //ũ���ͼ
int n,m;
bool judge(long long ans) //�ж�����ʹ𰸴�С��ϵ
{
    int cnt=0;//cntÿ��Ҫ����һ������
    cnt++;//��һͷţ����
    long long last=map1[0]; //����Ľڵ�
    for(int i=1;i<n;i++)
    {
        if(map1[i]-last>=ans)
        {
            cnt++; //�õ���ԣ���ţ����
            last=map1[i]; //����ڵ����
            if(cnt>=m)
            return true; //����ţ���ԴﵽҪ��ֵ��ans�����ٴ�һ��
        }
    }
    return false; //����ţ�ﲻ��Ҫ��ansӦ�ñ�Сһ�㡣
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>map1[i];
    }
    sort(map1,map1+n);
    long long left=0;
    long long right=map1[n-1]-map1[0];
    while(right>=left)
    {
        long long mid=(left+right)/2;
        if(judge(mid))
        {//ans�����ٴ�һ��
            left=mid+1;
        }
        else
        {//ansӦ��Сһ��
            right=mid-1;
        }
    }
    cout<<left-1;
    return 0;
}