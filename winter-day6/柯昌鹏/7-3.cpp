#include <iostream>
using namespace std;

int main ()
{
    int n,temp;
    cin>>n;
    int a[10000];
    for(int i=0;i<10000;i++) a[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        a[temp]++;
    }
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    for(int i=0;i<10000;i++)
    {
        if(a[i]!=0)
        {
            cout<<i<<":"<<a[i]<<endl;
        }
    }
    return 0;
}