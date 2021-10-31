#include <iostream>
using namespace std;
int main()
{
    long long n,i=1;
    int a,m,b=0;
    cin>>n>>m;
    while(i<=n)
    {
        cin>>a;
        if(a>=m) 
        {
            cout<<i<<endl;
            b=1;
            break;
        }
        else i++;
    }
     if(b==0) cout<<i<<endl;
    return 0;
}
