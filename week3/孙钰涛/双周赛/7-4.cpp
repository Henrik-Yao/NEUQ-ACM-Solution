#include<iostream>
using namespace std;
int main()
{
    int n;
    double zhu3[100],zhu4[100];
    zhu3[1]=1;zhu4[1]=1;
    for(int i=2;i<=64;i++) zhu3[i]=2*zhu3[i-1]+1;
    for(int i=2;i<=64;i++)
    {
        zhu4[i]=9999999999;
        for(int j=0;j<i;j++)
        {
            zhu4[i]=min(zhu4[i],2*zhu4[j]+zhu3[i-j]);
        }
    }
    while(cin>>n)
    {
        cout<<zhu4[n]<<"\n";
    }
    return 0;
}