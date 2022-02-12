#include<iostream>
#include<cstring>
using namespace std;
int gangs[1001];
int sum=0,fhd=0;
int main()
{
    memset(gangs,0,sizeof(gangs));
    int n,m,q,num1,num2;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) 
    {
        cin>>num1>>num2;
        if(gangs[num1] && gangs[num2] && gangs[num1]!=gangs[num2])
        {
            sum++;
            fhd++;
            int a=gangs[num1],b=gangs[num2];
            for(int j=1;j<=n;j++)
            {
                if(gangs[i]==a || gangs[i]==b)
                gangs[i]=sum;
            }
        }
        else if(gangs[num1] && gangs[num2] && gangs[num1]==gangs[num1])
            continue;
        else if(gangs[num1] && !gangs[num2]) gangs[num2]=gangs[num1];
        else if(gangs[num2] && !gangs[num1]) gangs[num1]=gangs[num2];
        else
        {
            sum++;
            gangs[num1]=sum;
            gangs[num2]=sum;
        }
    }
    for(int i=1;i<=n;i++)
        if(gangs[i]==0) sum++;
    for(int i=1;i<=q;i++)
    {
        cin>>num1>>num2;
        if(gangs[num1]==gangs[num2] && gangs[num1]!=0) cout<<"In the same gang.\n";
        else cout<<"In different gangs.\n";
    }
    cout<<sum-2*fhd;
}
