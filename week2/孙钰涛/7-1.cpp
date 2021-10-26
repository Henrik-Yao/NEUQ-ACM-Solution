#include<iostream>
#include<string>
using namespace std;

void move(string here,string to,string there,int num)
{
    if(num==0) return ;
    move(here,there,to,num-1);
    cout<<here<<"->"<<there<<"\n";
    move(to,here,there,num-1);
}
int main()
{
    int n;
    string s1,s2,s3;
    cin>>n>>s1>>s2>>s3;
    move(s1,s2,s3,n);
    return 0;
}