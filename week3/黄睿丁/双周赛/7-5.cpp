#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int y=0;y<t;++y)
    {
        int n,m,i,j,l;
        cin>>m;
        int a[m];
        for(i=0;i<m;++i)
            cin>>a[i];
        cin>>n;
        int b[n];
        for(i=0;i<n;++i)
            cin>>b[i];
        
        int c[m+n];
        l=0;
        i=0;
        j=0;
        while(i<m&&j<n)
        {
            if(a[i]>=b[j])
            c[l++]=b[j++];
            else
            c[l++]=a[i++];
        }
        while(i<m)
        c[l++]=a[i++];
        while(j<n)
        c[l++]=b[j++];
        
        for(i=0;i<m+n-1;++i)
            cout<<c[i]<<" ";
        cout<<c[i]<<endl;
    }
    
}
