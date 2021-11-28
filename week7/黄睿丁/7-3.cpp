#include <bits/stdc++.h>
using namespace std;
char a[1010];
string b,c;
int main()
{
    while(getline(cin,b)&&getline(cin,c))
    {
    int i,j;
    int lenb=b.length(),lenc=c.length();
    for(i=0;i<lenc;i++)
    {
            a[c[i]]=1;
    }
    for(i=0;i<lenb;i++)
    {
        if(a[b[i]]==0)
            cout<<b[i];
    }
    for(i=0;i<lenc;i++)
        a[c[i]]=0;
        cout<<endl;
    }
    
}
