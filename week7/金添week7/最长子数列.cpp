#include <bits/stdc++.h>
using namespace std;
int sum[10000000];
int a[100000000];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int remp;
        cin>>remp;
        for(int j=0;j<remp;j++)
        {
            cin>>a[j];
        }
        sum[0]=1;
        for(int j=1;j<remp;j++)
        {
            sum[j]=1;
            for(int k=0;k<j;k++)
            {
                if(a[k]<a[j])
                sum[j]=max(sum[k]+1,sum[j]);
            }
        }
        sort(sum,sum+remp);
        cout<<sum[remp-1];
        memset(sum,0,1000);
        memset(a,0,1000);
        cout<<endl;
        if(i!=num-1)
        cout<<endl;
    }



    return 0;
}