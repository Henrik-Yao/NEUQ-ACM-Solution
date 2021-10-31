#include <iostream>
using namespace std;
int main()
{
    int n,m,i;
    cin>>n>>m;
    int a[n+1],b[m][2];
    string A[n+1];
    for(i=1;i<n+1;i++)
        cin>>a[i]>>A[i];
    for(i=0;i<m;i++)
        cin>>b[i][0]>>b[i][1];
    int x=1;
    for(i=0;i<m;i++)
    {
        if(a[x]==b[i][0])
            x-=b[i][1];
        else
            x+=b[i][1];
        while(x<=0)
            x+=n;
        if(x>n&&x%n!=0)
            x=x%n;
        if(x%n==0)
            x=n;
    }
    cout<<A[x];
}
