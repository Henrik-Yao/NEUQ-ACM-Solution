#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num*2;i++)
    cin>>a[i];
    sort(a,a+num*2);
    cout<<(a[num]+a[num-1])/2<<endl;

    return 0;
}