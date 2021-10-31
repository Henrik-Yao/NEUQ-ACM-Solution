#include <iostream>
using namespace std;
void fen(int n,string s,string p,string e);
int main()
{
    int n;
    cin>>n;
    string s,p,e;
    cin>>s>>p>>e;
    fen(n,s,p,e);
}

void fen(int n,string s,string p,string e)
{
    if(n==0)
        return;
    fen(n-1,s,e,p);
    cout<<s<<"->"<<e<<endl;
    fen(n-1,p,s,e);
    
    
}
