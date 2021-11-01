#include <iostream>
using namespace std;
int n,a;
int maxx=a;
int maxn=0;
int main ()
{
    cin>>n;
    cin>>a;
    for(int i=0;i<n-1;i++)
    {
        cin>>a;
        if(maxx+a>a) maxx+=a;
        else maxx=a;
        if(maxn<maxx) maxn=maxx; 
        }
    cout<<maxn;
    return 0;
}
