#include <iostream>
using namespace std;
int main()
{
    int n,i,s,b=0,t=0;
    int a[10000];
    cin>>n;
    for(i=0;i<n;i++) 
    {
        cin>>a[i];
        if(a[i]>=0) b=1;
    }
    if(b==0) s=0;
    else 
    {
        for(i=0;i<n;i++)
        {
            t+=a[i];
            if(t<0) t=0;
            if(t>s) s=t;
        }
    }
    cout<<s<<endl;
    return 0;
}
