#include <iostream>
using namespace std;

bool a[10000010]={1,1};
int b[10000010],k=0;

int main ()
{
    int n,ans;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(!a[i]) b[++k]=i;
        for(int j=1;j<=k;j++)
        {
            if(i*b[j]>n) break;
            a[i*b[j]]=1;
            if(i%b[j]==0) break;
        }
    }
    for(int ss=1;ss<=n;ss++)
    {
       if(b[ss]!=0) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

