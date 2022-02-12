#include<iostream>
#include<cstring>
using namespace std;
int circle[1001];
int cnt=0,bug=0;
int main()
{
    memset(circle,0,sizeof(circle));
    int n,m,q,num1,num2;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++) 
    {
        cin>>num1>>num2;
        if(circle[num1] && circle[num2] && circle[num1]!=circle[num2])
        {
            cnt++;
            bug++;
            int a=circle[num1],b=circle[num2];
            for(int j=1;j<=n;j++)
            {
                if(circle[i]==a || circle[i]==b)
                circle[i]=cnt;
            }
        }
        else if(circle[num1] && circle[num2] && circle[num1]==circle[num1])
            continue;
        else if(circle[num1] && !circle[num2]) circle[num2]=circle[num1];
        else if(circle[num2] && !circle[num1]) circle[num1]=circle[num2];
        else
        {
            cnt++;
            circle[num1]=cnt;
            circle[num2]=cnt;
        }
    }
    for(int i=1;i<=n;i++)
        if(circle[i]==0) cnt++;
    for(int i=1;i<=q;i++)
    {
        cin>>num1>>num2;
        if(circle[num1]==circle[num2] && circle[num1]!=0) cout<<"In the same gang.\n";
        else cout<<"In different gangs.\n";
    }
    cout<<cnt-2*bug;
    return 0;
}