#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    while(getline(cin,a),getline(cin,b))
    {
        int al=a.length();
        int bl=b.length();
        for(int i=0;i<al;i++)
        {
            for(int j=0;j<bl;j++)
            {
                if(a[i]==b[j])
                {
                    a.erase(i--,1);
                }
            }
        }
        cout<<a<<endl;
    }
    return 0;
}