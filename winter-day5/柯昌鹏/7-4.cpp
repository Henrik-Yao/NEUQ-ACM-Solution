#include <iostream>
using namespace std;

int n,m,k,a[1005],judge=-1;

int main ()
{
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>k;
    //接下来是查找
    int l=0,r=n-1;
    while(l<=r)
    {
        cnt++;
        int mid=l+(r-l)/2;
        if(a[mid]>=k) r=mid-1;
        else l=mid+1;
        // cout<<a[mid]<<" ";
    }
    // cout<<endl;
    if(a[l]==k) cout<<l<<endl;
    else cout<<judge<<endl;//这个judge只是输出-1而已
    return 0;
}