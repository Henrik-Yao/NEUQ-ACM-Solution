#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[100000];
    cin>>str;
    long long len=strlen(str);
    bool flag=true;
    for(int i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-1-i])
        {
            flag=false;
            break;
        }
        // cout<<str[i]<<" "<<str[len-1-i]<<endl;
    }
    if(flag)
    cout<<"yes"<<endl;
    else
    cout<<"no"<<endl;
    return 0;
}