#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1000001],l[1000001],r[1000001],result[1000001],num[100001];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    l[0]=1;num[a[0]]++;
    for(int i=1;i<n;i++)
    {
        if(num[a[i]]!=0) l[i]=l[i-1];
        else
        {
            l[i]=l[i-1]+1;
            num[a[i]]++;
        }
    }

    memset(num,0,sizeof(num));

    r[n-1]=1;num[a[n-1]]++;
    for(int i=n-2;i>=0;i--)
    {
        if(num[a[i]]!=0) r[i]=r[i+1];
        else
        {
            r[i]=r[i+1]+1;
            num[a[i]]++;
        }
    }
    for(int i=0;i<n-1;i++) result[i]=l[i]+r[i+1];
    sort(result,result+n);
    cout<<result[n-1];
    return 0;
}