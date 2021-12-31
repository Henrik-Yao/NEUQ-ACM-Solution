#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n==1) return 1;
    else{
    int tot=1;
    for(int i=1;i<n;i++)
    {
        if(n%i==0) tot+=sum(i);
    }
    return tot;
    }
}
int main ()
{
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}
