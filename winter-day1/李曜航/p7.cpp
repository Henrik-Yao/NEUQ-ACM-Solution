#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{
    // freopen("read.in","r",stdin);
    string a;
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='A') printf("sae");
        else if(a[i]=='B') printf("tsaedsae");
        else if(a[i]=='(')
        {
            int start = ++i, end = 0;
            printf("%c",a[i]);
            for(int j=i;j<=a.length();j++)
                if(a[j]==')') end = j-1;
            while(end>start)
                printf("%c%c",a[end--],a[start]);
        }
    }


}