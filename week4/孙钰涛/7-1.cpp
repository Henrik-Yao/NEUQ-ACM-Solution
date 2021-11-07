#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a,b,num[10001];
    while(cin>>a>>b)
    {
        memset(num,0,sizeof(num));
        num[0]=1;num[1]=1;
        for(int i=2;i<=b;i++)
        {
            if(num[i]==0)
            {
                for(int j=i*i;j<=b;j=j+i)
                {
                    num[j]=1;
                }
            }
        }
        int first=1;
        for(int i=a;i<=b;i++)
        {
            if(first==1 && num[i]==0)
            {
                cout<<i;
                first--;
            }
            else if(num[i]==0) cout<<" "<<i;
        }
        cout<<"\n";
    }
    return 0;
}