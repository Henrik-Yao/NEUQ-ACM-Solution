#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[100] = {0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a[temp]++;
    }
    for(int i=0;i<100;i++)
    {
        if(a[i])
        {
            cout<<i<<":"<<a[i]<<endl;
        }
    }

    return 0;
}

