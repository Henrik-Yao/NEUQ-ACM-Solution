#include<iostream>
#include<algorithm>
using namespace std;
int a[10001];
int he(int lz,int yz)
{
    if(lz==yz)return a[lz];
    else
    {
        int mid=(lz+yz)/2;
        int l_maxq=he(lz,mid),r_maxq=he(mid+1,yz);
        int l_sum=0,r_sum=0;
        int l_max=-10000000,r_max=-10000000;
        for(int i=mid;i>=lz;i--)//[lz,mid]
        {
            l_sum+=a[i];
            l_max=max(l_sum,l_max);
        }
        for(int i=mid+1;i<=yz;i++)
        {
            r_sum+=a[i];
            r_max=max(r_max,r_sum);
        }
        return max(max(l_maxq,r_maxq),max(max(l_max,0)+r_max,max(r_max,0)+l_max));//之前左边最大，之前右边最大，现在（左，右，左+右）最大
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int end=he(1,n);
    cout<<max(end,0)<<endl;
}