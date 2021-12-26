#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    bool jud=1;
    for(int i=0;i<str.length()/2;i++) 
    if(str[i]!=str[str.length()-i-1]) 
    {
        jud=0;
        break;
    }
    if(jud) cout<<"yes";
    else cout<<"no";
    return 0;
}
