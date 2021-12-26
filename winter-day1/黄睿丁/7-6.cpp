#include <iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,l=s.length(),flag=1;
    
    for(i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-i-1])
        {
            
            flag=0;
            break;
        }
    }
    if(flag==0)
        cout<<"no";
    else
        cout<<"yes";
}
