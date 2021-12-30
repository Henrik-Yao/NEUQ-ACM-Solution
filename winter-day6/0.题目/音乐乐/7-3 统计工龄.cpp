#include<bits/stdc++.h>
using namespace std;
int a[51];

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
    }
    for(i=0;i<=50;i++)
    {
        if(a[i])
            cout<<i<<':'<<a[i]<<endl;
    }
    return 0;
}
