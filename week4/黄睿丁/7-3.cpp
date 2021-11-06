#include <iostream>
using namespace std;
int b[10000001];
bool a[10000001];
int main()
{
    int i,j,count=0;
    a[1]=1;
    a[0]=1;
    for(i=2;i<=10000000;i++)
    {
        if(!a[i])
        {
            b[++b[0]]=i;
        }
        for(j=1;j<=b[0]&&i*b[j]<=10000000;j++)
        {
            a[i*b[j]]=1;
            if(i%b[j]==0)
                break;
        }
    }
    int n;
    cin>>n;
    for(i=1;i<=n;i++)
        if(a[i]==0)
            count++;
    cout<<count<<endl;
    
}
