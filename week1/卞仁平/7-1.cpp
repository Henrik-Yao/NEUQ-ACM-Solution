#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i;
    string k;
    int ll=s.length();
    for(i=1;i<=n;i++)
    {
        cin>>k;
        int c=0;
        int l=k.length();
        for(int j=0;j<=ll;j++)
        {
            if(k==s.substr(j,l))c++;
        }
        cout<<c<<endl;
    }
    return 0;
}