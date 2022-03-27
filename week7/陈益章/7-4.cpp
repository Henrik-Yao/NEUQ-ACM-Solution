#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[10005],num[10005];
int main()
{
	int n,m,a[1005],num[1005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=1005;k++)
            num[k]=1;
        int mmax=-1;
        cin>>m;
        for(int j=1;j<=m;j++)
            cin>>a[j];
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(a[j]>a[k]) num[j]=max(num[j],num[k]+1);
            }
            mmax=max(mmax,num[j]);
        }
        cout<<mmax;
        if(i!=n) cout<<"\n\n";
        else cout<<"\n";
    }
	}
