#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int i;
    while(getline(cin,s1),getline(cin,s2))
    {
        map<char,int>m;
        for(i=0;i<s2.size();i++)
        {
            m[s2[i]]=1;
        }
        for(i=0;i<s1.size();i++)
        {
            if(m.find(s1[i])!=m.end())
            {
                continue;
            }
            else
            {
                cout<<s1[i];
            }
        }
        cout<<endl;
    }
    return  0;
}
