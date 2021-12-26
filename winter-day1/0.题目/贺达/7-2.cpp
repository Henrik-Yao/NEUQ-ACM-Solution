#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<char>v;

int main()
{
    int i=0;
    int ins=0;
    char c;
    while(cin.get(c))
    {
        if(c<='z'&&c>='a'||c==' ')
        {
            if(ins==0)
            {
                v.insert(v.begin()+i,c);
                i++;
            }
            else
            {
                v.erase(v.begin()+i);//unsure
                v.insert(v.begin()+i,c);
                i++;
            }
        }
        if(c=='[')
        {
            i=0;
        }
        if(c==']')
        {
            i=v.size();
        }
        if(c=='{')
        {
            if(i>0)
            {
              i--;
            }
        }
        if(c=='}')
        {
            if(i<v.size())
            {
               i++;
            }
        }
        if(c=='-')
        {
            if(ins==0)
            {
                ins=1;
            }
            else
            {
                ins=0;
            }
        }
        if(c=='=')
        {
            v.erase(v.begin()+i-1);
            i--;
        }
    }
    int t=v.size();
    for(int j=0;j<t;j++)
    {
        cout<<v[j];
    }
    return 0;
}
