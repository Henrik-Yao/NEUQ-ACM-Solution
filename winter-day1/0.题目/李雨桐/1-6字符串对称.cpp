#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    bool flag=true;

    cin>>s;
    int lens=s.size();


    for (int i=0;i<lens/2;i++)
    {
        if(s[i]!=s[lens-1-i])
        {
            flag=false;
            break;
        }
    }
    if(flag==false)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;

    return 0;
}
