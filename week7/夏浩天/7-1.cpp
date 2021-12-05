#include<iostream>
#include<map>
using namespace std;
map<string,string> dic;
int main()
{
    int n,m;cin>>n>>m;
    while(n--)
    {
        string lsz1,lsz2;cin>>lsz1>>lsz2;
        dic[lsz2]=lsz1;
    }
    while(m--)
    {
        string lsz;cin>>lsz;
        if(dic[lsz]=="")cout<<"eh"<<endl;
        else cout<<dic[lsz]<<endl;
    }
}