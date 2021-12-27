#include<bits/stdc++.h>
using namespace std;
int a[10009],cnt;
int main()
{
    while(cin>>a[cnt])
    {
        cnt++;
    }
    sort(a,a+cnt);
    for(int i=0;i<cnt;i++) 
    {
        if(i==0) printf("%d",a[i]);
        else printf("->%d",a[i]);
    }
    cout<<endl;
    bool flag=0;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]%2==1)
        {
            if(flag==0) 
            {
                printf("%d",a[i]);
                flag=1;
            }
            else printf("->%d",a[i]);
        }
    }
    cout<<endl;
    flag=0;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]%2==0)
        {
            if(flag==0) 
            {
                printf("%d",a[i]);
                flag=1;
            }
            else printf("->%d",a[i]);
        }
    }
    return 0;
}
