#include<bits\stdc++.h>
using namespace std;
vector<int>nmd;
int t,n,a[1001]={0};

void get_mid(int n)
{
    if(a[n]==0) return ;
    get_mid(2*n);
    nmd.push_back(a[n]);
    get_mid(2*n+1);
}

int get_deep(int n)
{
    if(a[n]==0) return 0;
    int x=get_deep(2*n);
    int y=get_deep(2*n+1);
    return max(x,y)+1;
}

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        nmd.clear();
        memset(a,0,sizeof(a));
        for(int j=1;j<=n;j++)
            cin>>a[j];
        get_mid(1);
        for(int j=0;j<nmd.size();j++)
        {
            cout<<nmd[j];
            if(j!=nmd.size()-1) cout<<" ";
        }
        cout<<"\n"<<get_deep(1)<<"\n";
    }
    return 0;
}