#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int lis[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            lis[i]=1;
        }
        //memset(lis,1,sizeof(lis));
        //查到的memset给int型的数组赋非零值会有点问题
        for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        if(a[i]>a[j])
        {
            lis[i]=max(lis[j]+1,lis[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,lis[i]);
        cout<<ans<<endl;
        if(t) printf("\n");
    }
    return 0;
}