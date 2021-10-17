#include <iostream>
using namespace std;
int a[1000001],cnt1[1000001]={0},cnt2[1000001]={0};

int main()
{
    int n,ans1=0,ans2=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(cnt1[a[i]]==0) ans1++;
        cnt1[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(cnt1[a[i]]==1) ans1--;
        cnt1[a[i]]--;
        if(cnt2[a[i]]==0) ans2++;
        cnt2[a[i]]++;
        ans=max(ans,ans1+ans2);
    }
    cout<<ans;
    return 0;
}
