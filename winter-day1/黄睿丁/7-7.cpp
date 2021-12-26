#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,S;
    cin>>s;
    int i,j;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            
            i++;
            if(s[i]!=')')
            {
                char c=s[i];
                j=i;
                while(s[j]!=')')
                    j++;
                j--;
                int end=j;
                for(i+=1;i<=end;i++)
                {
                    S.push_back(c);
                    S.push_back(s[j]);
                    j--;
                }
                S.push_back(c);
            }
        }
        else if(s[i]=='B')
        {
            S.append("tsaedsae");
        }
        else if(s[i]=='A')
        {
            S.append("sae");
        }
        else if(s[i]!='#')
        {
            S.push_back(s[i]);
        }
    }
    cout<<S;
}
