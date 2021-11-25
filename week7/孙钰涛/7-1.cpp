#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,string>connect;
int main()
{
    int n,m;
    string rua,eng;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>eng>>rua;
        connect[rua]=eng;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>rua;
        if(connect[rua]=="") cout<<"eh\n";
        else cout<<connect[rua]<<"\n";
    }
    return 0;
}