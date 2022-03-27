#include<bits/stdc++.h>
using namespace std;
string str;
bool check(string str)
{
    int len=str.size();
    for(int i=0;i<(str.size()-1)/2;i++)
    {
        if(str[i]!=str[len-i-1])
        return false;
    }
    return true;
}
int main()
{
    cin>>str;
    if(check(str)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
