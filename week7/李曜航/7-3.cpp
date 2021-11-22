#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a,b;
map <char,int> m;
int main()
{
    // freopen("read.in","r",stdin);
    while(getline(cin,a))
    {
        m.clear();
        getline(cin,b);
        for(int i=0;i<b.length();i++)
        {
            m[b[i]]++;
        }
        for(int i=0;i<a.length();i++)
        {
            if(m[a[i]]) continue;
            cout<<a[i];
        }
        cout<<endl;
    }
	return 0;

}


