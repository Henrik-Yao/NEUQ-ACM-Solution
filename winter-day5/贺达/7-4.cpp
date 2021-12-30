#include<bits/stdc++.h>
using namespace std;
int a[1001];
int cnt=0;
int se(int l,int r,int key)
{
    int mid=(l+r)/2;
    if(l>r)
    {
        return -1;
    }
    if(key==a[mid])
    {
        cnt++;
        return mid;
    }
    else if(key>a[mid])
    {
        l=mid+1;
        cnt++;
        se(l,r,key);
    }
    else
    {
        r=mid-1;
        cnt++;
        se(l,r,key);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<se(0,n-1,key)<<endl;
    cout<<cnt;

    return 0;
}
