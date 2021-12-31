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