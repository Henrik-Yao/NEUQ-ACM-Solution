#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[10000];
    int total = 0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]-a[j]==1 || a[i]-a[j]==-1)
            {
                total++;
            }
        }
    }
    cout<<total;

    return 0;
}
