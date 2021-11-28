#include <iostream>
#include <map>
using namespace std;
map<string,string> di;
int main()
{
    int m,n;
    cin>>n>>m;
    for(int q=0;q<n;q++)
    {
        string a,b;
        cin>>a>>b;
        di[b]=a;   
    }
    for(int w=0;w<m;w++)
    {
        string c;
        cin>>c;
        if(di.count(c))
            cout<<di[c]<<endl;
        else
            cout<<"eh"<<endl;
    }
}
