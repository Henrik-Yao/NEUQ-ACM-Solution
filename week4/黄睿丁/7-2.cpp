#include <iostream>
using namespace std;
int main()
{
    int a[45];
    a[0]=0;
    a[1]=1;
    a[2]=2;
    int i,c,b;
    for(i=3;i<=45;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    cin>>c;
    for(i=0;i<c;i++)
    {
        cin>>b;
        cout<<a[b-1]<<endl;
    }
}
