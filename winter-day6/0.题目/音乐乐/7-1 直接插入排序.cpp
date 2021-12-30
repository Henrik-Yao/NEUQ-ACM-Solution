#include<bits/stdc++.h>
using namespace std;
int n,a[101];

int main()
{
    int i,j;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        cin>>a[i];
        for(i=1;i<n;i++)
        {
            int temp=a[i];
            if(a[i]<a[i-1])
            {
                for(j=i-1;temp<a[j];j--)
                    a[j+1]=a[j];
                a[j+1]=temp;
            }
            for(j=0;j<n-1;j++)
                cout<<a[j]<<' ';
            cout<<a[j]<<endl;
        }
    }
    return 0;
}
