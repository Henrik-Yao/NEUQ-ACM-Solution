#include <bits/stdc++.h>
using namespace std;
void hnt(int n,string a,string b,string c)
{
    if(n==1)
    {
        cout<<a<<"->"<<c<<"\n";
    }
    else 
    {
        hnt(n-1,a,c,b);
        cout<<a<<"->"<<c<<"\n";
        hnt(n-1,b,a,c);
    }
}
int main()
{
    int n;
    string a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    hnt(n,a,b,c);
    return 0;

}