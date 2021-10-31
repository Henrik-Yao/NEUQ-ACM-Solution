#include <iostream>
using namespace std;
int a[501],b[501][501],s=0,flag=0;
int sou(int A,int B,int n);
int main()
{
    int n,m,j,i,k,A,B;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j>>k;
        b[j][k]=1;
    }
    cin>>A>>B;
    a[B]=1;
    s=sou(A,B,n);
    cout<<s;
    if(flag==0)
        cout<<" Yes\n";
    else
        cout<<" No\n";
}

int sou(int A,int B,int n)
{
    
    if(a[A]==1)
    return a[A];
    int f=0,i;
    for(i=1;i<=n;i++)
    {
        if(b[A][i]==1)
        {
            f=1;
            a[A]+=sou(i,B,n);
        }
    }
    if(f==0)
    flag=1;
    return a[A]; 
}

