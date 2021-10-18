#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,T,happy[100000];
    cin>>n>>T;
    for(int i=0;i<n;i++)
    {
        int v,t;
        cin>>v>>t;
        if(t<=T) happy[i]=v;
        else happy[i]=v-(t-T);
    }
    sort(happy,happy+n);
    cout<<happy[n-1];

    return 0;
}