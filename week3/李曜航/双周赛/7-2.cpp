#include <bits/stdc++.h>
using namespace std;
int n;
string a, b, c;
void luohan(int num, string from, string to, string tmp)
{
    if(num==1) cout<<from<<"->"<<to<<endl;
    else
    {
        luohan(num-1,from,tmp,to);
        cout<<from<<"->"<<to<<endl;
        luohan(num-1,tmp,to,from);
    }
}
int main()
{
    cin>>n;
    cin>>a>>b>>c;
    luohan(n,a,c,b);
}