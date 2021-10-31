#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s=0;
    cin>>n;
    char a[50001],b[21];
    cin>>a;
    for(int i=0;i<n;i++)
    {
        int flag=1,A,B;
        s=0;
        cin>>b;
        A=strlen(a);
        B=strlen(b);
        for(int j=0;j<A-B+1;j++)
        {
            if(a[j]==b[0]&&a[j+B-1]==b[B-1])
            {
                for(int l=j;l<j+B-1;l++)
                {
                    if(a[l]!=b[l-j])
                    {
                        flag=0;
                        break;
                    }
                }
                s+=flag;
            }
        }
        if(i!=n-1)
        cout<<s<<endl;
    }
    cout<<s;
}
