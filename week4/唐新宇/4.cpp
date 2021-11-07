#include<bits/stdc++.h>

using namespace std;

long long   y(int a,int b,int c)
{
    if(b==0)return 1%c;
    else if(b==1)return a%c;
    else return (y(a,b/2,c)*y(a,b-b/2,c))%c;
}

int main()
{
    int n;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        cin>>a[i][1];
        cin>>a[i][2];
    }
    for(int i=0;i<n;i++)
    {
        cout<<y(a[i][0],a[i][1],a[i][2])<<endl;

    }



    return 0;
}
