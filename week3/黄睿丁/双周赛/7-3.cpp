#include <iostream>
using namespace std;
int main()
{
    unsigned long long a[36];
    a[1]=2;
    for(int i=2;i<36;i++)
        a[i]=3*a[i-1]+2;
    int n;
    while(cin>>n)
    cout<<a[n]<<endl;;
}
