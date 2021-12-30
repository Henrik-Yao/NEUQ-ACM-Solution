#include <iostream>
using namespace std;

int findmid(int a[],int b[],int n)
{
    int i,j;
    i=j=0;
    while((i+j)<n-1)
    {
        if(a[i]>b[j])
        {
            j++;
        }
        else i++;
    }
    return a[i]>b[j]?b[j]:a[i];
}

int main ()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++) cin>>b[j];
    cout<<findmid(a,b,n)<<endl;
    return 0;
}