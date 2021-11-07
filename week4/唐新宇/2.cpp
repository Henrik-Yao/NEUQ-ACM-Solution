#include<bits/stdc++.h>

using namespace std;

long long  y(int a)
{
    if(a==1)return 0;
    else if(a==2)return 1;
    else if(a==3)return 2;
    else return y(a-1)+y(a-2);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1)cout<<y(a[i])<<endl;
        else cout<<y(a[i]);
    }



    return 0;
}
