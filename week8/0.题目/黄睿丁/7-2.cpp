#include <iostream>
using namespace std;
int a[1000010];
int main()
{
    int n;
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++)
        cin>>a[i];
    j=1;
    int pace=0;
    int maxm;
    while(1)
    {
        if(a[j]>=n-j)
            break;
        int step=0;
        for(i=1;i<=a[j];i++)
        {
            if(i+a[i+j]>step)
            {
                step=i+a[i+j];
                maxm=i;
            }
        }
        j+=maxm;
        pace++;
    }
    pace++;
    cout<<pace;
    
}
