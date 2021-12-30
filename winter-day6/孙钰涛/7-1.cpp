#include<iostream>
using namespace std;
int main()
{
    int n,a[101],temp;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            temp=a[i];
            int j=i-1;
            while(j>=1 && temp<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=temp;

            for(int j=1;j<=n-1;j++)
                cout<<a[j]<<" ";
            cout<<a[n]<<"\n";
        }
    }
    return 0;
}