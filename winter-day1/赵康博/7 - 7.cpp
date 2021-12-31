#include <bits/stdc++.h>
using  namespace  std;
#define  N 10000
int main()
{
    char  f[N];
    cin>>f;
    string s;
    for(int i = 0; i < strlen(f); i++)
    {
        if(f[i]=='B')s+="tsaedsae";
        else if(f[i]=='A')s+="sae";
        else if(f[i]=='(')
        {
            int t1 = i;
            while (f[i]!=')')
            {
                i++;
            }
            int t2 = i;
            char x = f[t1+1];
            for(int j = t2 - 1; j > t1 + 1; j--)
            {
                s+=x;
                s+=f[j];
            }
            s+=x;
        }

    }
    cout<<s<<endl;
    return 0;
}