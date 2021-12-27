#include <bits/stdc++.h>
using namespace std;
//树状数组
//lowbit函数

long long  d[1000000],n;//树状数组和原数组长度
long long lowbit(int x)
{
    return x&(-x);//得到该数二进制最低位值
    
}
void update(int x,int y)//x为位点下标，y为修改增加值
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        d[i]+=y; //实现更新
    }
}
long long query(int x)//访问从1到x的数组和（前缀和）
{
    long long sum=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        sum+=d[i];
    }
    return sum;
}
int main()
{
    int num;//输入测试次数
    cin>>n>>num;
    for(int i=1;i<=n;i++)
    {
        int remp; 
        cin>>remp;
        update(i,remp);//实现数组初始化
    }
    for(int i=0;i<num;i++)
    {
        int remp;
        cin>>remp;
        int remp1,remp2;
        if(remp==1)
        {
            cin>>remp1>>remp2;
            update(remp1,remp2);//实现更新操作
        }
        else
        {
            cin>>remp1>>remp2;
            cout<<query(remp2)-query(remp1-1)<<endl;
        }
    }

    return 0;
}