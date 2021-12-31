#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int a[10000];
int b[10000];
int cc=0;
int main()
{
    int c;
    while(cin>>c)
    {
         a[cnt]=c;
         cnt++;
    }
    sort(a,a+cnt);
    for(int i=0;i<cnt;i++)
    {
        cout<<a[i];
        if(i!=cnt-1)
        {
            cout<<"->";
        }
        if(a[i]%2!=0)//奇数
        {
            b[i]=1;
            cc++;
        }
    }
    cout<<endl;
    int cj,co;
    cj=co=0;
    for(int i=0;i<cnt;i++)
    {
        if(b[i]==1)
        {
            cout<<a[i];
            cj++;
            if(cj!=cc)
            {
                cout<<"->";
            }
        }
    }
    cout<<endl;
    for(int i=0;i<cnt;i++)
    {
        if(b[i]==0)
        {
            cout<<a[i];
            co++;
            if(co!=(cnt-cc))
            {
                cout<<"->";
            }
        }
    }
    return 0;
}
