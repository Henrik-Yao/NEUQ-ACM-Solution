#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int n;
int a[1010];
int main()
{
    cin>>n;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {

        for(int j=i+1;j<n;j++)
        {
             t=abs(a[i]-a[j]);
            if(t==1)
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
