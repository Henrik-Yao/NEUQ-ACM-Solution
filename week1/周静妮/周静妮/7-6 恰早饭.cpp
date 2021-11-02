#include <iostream>
using namespace std;
int main()
{
    int n,T,v,t,i;
    cin>>n>>T;
    int c[n];
    for(i=0;i<n;i++)
    {
        cin>>v>>t;
        if(t<T) c[i]=v;
        else c[i]=v-(t-T);
    }
    for(i=1;i<n;i++)
    {
        if(c[0]<c[i]) c[0]=c[i];
    }
    cout<<c[0];
    return 0;
}
