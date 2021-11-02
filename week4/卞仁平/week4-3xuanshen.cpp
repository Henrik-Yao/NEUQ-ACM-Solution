#include <bits/stdc++.h>
using namespace std;
#define max 10000001
//玄神的“埃氏筛”，我也不知道为啥这个叫埃氏筛
bool is[max];
int main()
{
    int n;
    cin>>n;
    int s=0;
    for(int i=2;i<=n;i++)
    {
        if(is[i])continue;
        s++;
        for(int j=i;j<=n;j+=i)
        //我试着用long long j=i*i,pta提示段错误？？？
        is[j]=1;
    }
    cout<<s;
    return 0;
}
//现在看懂了，maybe。
//j+=i即j是i的n倍，这些都不是素数