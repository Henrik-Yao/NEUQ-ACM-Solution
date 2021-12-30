#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[105];
	int n;
	while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(a[i]>=a[j-1]&&a[i]<=a[j])
                {
                    int temp=a[i];
                    for(int m=i;m>=j+1;m--)
                    a[m]=a[m-1];
                    a[j]=temp;
                    break;
                }
            }
            for(int j=1;j<n;j++)
            cout<<a[j]<<" ";
            cout<<a[n]<<endl;
        }
    }
	
}
