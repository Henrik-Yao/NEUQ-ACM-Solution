#include<iostream>
using namespace std;

int num[1000001];
int minBound(int *a,int x,int y,int t)
{
    int temp;
    while(x < y)
    {
        int T;
        T = (y-x)/2;
        temp = x + T;
        if(a[temp] >= t)
        {
            y = temp;
        }
        else
        {
            x = temp + 1;
        }
    }
    return x;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(size_t i = 0;i<n;i++)//size_t记录大小的数据类型
    {
        cin>>num[i];
    }
    if(num[n-1] >= m)
    {
        cout<<1 + minBound(num,0,n-1,m);
    }
    else
    {
        cout<<n + 1;
    }

    return 0;
}

//读入对比数，在读取时进行对比，若符合条件则记录位置