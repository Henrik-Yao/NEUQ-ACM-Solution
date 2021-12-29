#include<bits/stdc++.h>
using namespace std;

int a[110];

int se(int n,int key)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        {
            return mid+1;
        }
        else if(a[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return 0;
}

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
            if(i!=n-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int k;
            cin>>k;
            cout<<se(n,k);
            if(i!=m-1)
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
