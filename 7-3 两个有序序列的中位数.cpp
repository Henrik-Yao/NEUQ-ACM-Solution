#include<bits/stdc++.h>
using namespace std;

int a[200001];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+2*n);
    cout<<(a[n-1]+a[n])/2<<endl;
    return 0;
}


