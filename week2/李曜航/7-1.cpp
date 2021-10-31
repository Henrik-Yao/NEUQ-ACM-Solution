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
int n;
string a, b, c;

void luohan(int num, string from, string to, string emp)
{
    if(num==1) cout<<from<<"->"<<to<<endl;
    else
    {
        luohan(num-1,from,emp,to);
        cout<<from<<"->"<<to<<endl;
        luohan(num-1,emp,to,from);
    }
}
int main()
{
    n = read();
    cin>>a>>b>>c;
    // n = 2;
    // a = 'a';
    // b = 'b';
    // c = 'c';
    luohan(n,a,c,b);
}