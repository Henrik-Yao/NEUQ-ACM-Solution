#include <iostream>
using namespace std;
int fen(int n);
int main()
{
    int n,s=0;
    cin>>n;
    s=fen(n);
    cout<<s;
    
}

int fen(int n)
{
    int t=1;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            t+=fen(i);
        }
    }
    return t;
    
}
