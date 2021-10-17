#include <iostream>
using namespace std;
struct cai{
    int v;
    int t;
}H[100001];
int main()
{
    int n,T;
    cin>>n>>T;
    for(int i=0;i<n;i++)
    {
        cin>>H[i].v>>H[i].t;
    }
    for(int i=0;i<n;i++)
    {
        if(H[i].t>T) H[i].v-=H[i].t-T;
    }
    int max=H[0].v;
    for(int i=1;i<n;i++)
    {
        if(max<H[i].v) max=H[i].v;
    }
    cout<<max;
    return 0;
}
