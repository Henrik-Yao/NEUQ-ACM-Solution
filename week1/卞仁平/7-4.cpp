#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
    cin>>n;
    int i;
    double a[n+1];
    a[1]=1;a[2]=2;
    for(i=3;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        if(i%j==0)//约数
        {
            a[i]+=a[j];
        }
        a[i]++;

    }
    cout<<a[n];
    return 0;


    
}