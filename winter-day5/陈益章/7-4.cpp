#include<iostream>
using namespace std;
int cnt=0,n,a[1001],x;
int l,r;
bool find_ans(int x)
{
    int m,cnt=m,temp=a[1]+x;
    cnt--;
    for(int i=2;i<=n;i++)
    {
        if(temp<=a[i])
        {
            cnt--;
            temp=a[i]+x;
        }
    }
    if(cnt<=0) return 1;
    else return 0;
}

int find()
{
    while (l<=r)
    {
        cnt++;
        int mid=(l+r)/2;
        if(x==a[mid]) return mid;
        if(x>a[mid]) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main()
{
    
    cin>>n;
    l=0;
    r=n-1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    cout<<find()<<"\n"<<cnt;///////////
}
