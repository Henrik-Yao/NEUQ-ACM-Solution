#include<bits/stdc++.h>
using namespace std;
long long int HN3(long long int n);
long long int a[70];
long long int n;
int main()
{  
    
    while(cin>>n)
    {   a[n]=HN3(n);
        cout<<a[n]<<endl;
    }
    return 0;
}

long long int HN3(long long int n)
{   if(a[n]!=0) return a[n];
    if(n==1) return 2;
    else return HN3(n-1)+HN3(n-1)+HN3(n-1)+2;
}
