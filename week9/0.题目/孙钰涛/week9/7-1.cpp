#include<iostream>
using namespace std;
int main()
{
    int n;
    long long num[51];
    num[0]=0;
    num[1]=1;
    num[2]=2;
    num[3]=4;
    num[4]=7;
    for(int i=5;i<=50;i++)
    num[i]=num[i-1]+num[i-2]+num[i-3];
    while(cin>>n)
    {
        cout<<num[n]<<"\n";
    }
    return 0;
}