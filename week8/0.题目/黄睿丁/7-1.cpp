#include <iostream>
#include <algorithm>
using namespace std;
typedef struct a
{
    int start;
    int end;
}act;
bool cmp(act a,act b)
{
    return a.end<b.end;
}
int main()
{
    int t;
    cin>>t;
    for(int q=0;q<t;q++)
    {
        int n;
        cin>>n;
        int i,j;
        act a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i].start>>a[i].end;
        }
        sort(a,a+n,cmp);
        int now=0;
        int sum=1;
        for(j=1;j<n;j++)
        {
            if(a[j].start>=a[now].end)
            {
                now=j;
                sum++;
            }
        }
        cout<<n-sum<<endl;
    }
}
