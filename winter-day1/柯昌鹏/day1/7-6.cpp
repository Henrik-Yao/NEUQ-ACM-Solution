#include <iostream>
using namespace std;

int main ()
{
    string a;
    cin>>a;
    int flag=1;
    int k=a.length();
    for(int i=0;i<a.length()/2;i++)
    {
        if(a[i]!=a[k-i-1]) flag=0;
    }
    if (flag==1) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}