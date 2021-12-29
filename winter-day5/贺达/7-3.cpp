#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n;
int arr[200005];
int a[100005];
int b[100005];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int p,q;
    p=q=0;
    for(int i=0;i<n*2;i++)
    {
        if(a[p]<=b[q]&&p<n)
        {
            arr[i]=a[p];
            p++;
        }
        else if(a[p]>b[q]&&q<n)
        {
            arr[i]=b[q];
            q++;
        }
        else if(p>=n&&q<n)
        {
            arr[i]=b[q];
            q++;
        }
        else if(p<n&&q>=n)
        {
            arr[i]=a[p];
            p++;
        }
    }
    int t=(n*2-1)/2;
    cout<<arr[t];
    return 0;
}
