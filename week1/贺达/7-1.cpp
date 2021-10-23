#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    for(int i=1;i<=n;i++)
    {
        int count=0;
        string c;
        cin>>c;
        int len = s.length();
        for(int j=0;j<len;j++)
        {
                int p=0;
                for(int k=0;k<c.length();k++)
                {
                    if(s[j+k]!=c[k])
                    {
                        p++;
                        break;
                    }
                }
                if(p==0)
                {
                    count++;
                }
        }
        cout<<count<<endl;
    }
    return 0;
}
