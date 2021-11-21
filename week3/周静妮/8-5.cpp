#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int i,j,k,t,m,n,d;
    int a[100],b[100],c[200];
    cin>>t;
    for(k=0;k<t;k++)
    {
        memset(a,0,100);
        memset(b,0,100);
        cin>>m;
        for(i=0;i<m;i++) cin>>a[i];
        cin>>n;
        for(i=0;i<n;i++) cin>>b[i];
        i=j=d=0;
        while(i<m&&j<n)
        {
            if(a[i]<b[j]) c[d++]=a[i++];
            else c[d++]=b[j++];
        }
        while (i<m) c[d++]=a[i++];
        while (j<n) c[d++]=b[j++];
        for(i=0;i<d;i++) 
        {
            cout<<c[i];
            if(i<d-1) cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
