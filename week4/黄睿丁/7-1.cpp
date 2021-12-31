#include <bits/stdc++.h>
using namespace std;
int x[10001],y[10001];
int main()
{
   int i,j;
    x[0]=1;
    x[1]=1;
    for(i=2;i<=10000;i++)
    {
        if(!x[i])
        {
            y[++y[0]]=i;
        }
            for(j=1;j<=y[0]&&i*y[j]<=10000;j++)
            {
                x[i*y[j]]=1;
                if(i%y[j]==0)
                    break;
            }
        }
    
        int a,b,f=0;
        while(cin>>a>>b)
        {
            f=0;
            for(i=a;i<=b;i++)
            {
                
                if(x[i]==0)
                {
                    if(f==1)
                    cout<<j<<" ";
                    j=i;
                    f=1;
                }
            }
            cout<<j;
            cout<<endl;
        }
    
    
}
