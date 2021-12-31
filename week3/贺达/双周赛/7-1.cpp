#include<bits/stdc++.h>
using namespace std;

int count=0;


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum,m;
    sum=m=0;
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=i;k<j;k++)
            {
                sum=sum+a[k];
            }
            if(sum>m)
            {
                m=sum;
            }
        }
    }
    cout<<m;
    return 0;
}
