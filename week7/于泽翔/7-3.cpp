#include <bits/stdc++.h>
using namespace std;
map <char, int> M;
string s, b;
int m[666];
int main(void)
{
    while(getline(cin, s)&&getline(cin, b))
    {
    	int l_s=s.length(), l_b=b.length();
    	for(int i=0; i<l_b; i++)
    		m[b[i]]=1;
    	for(int i=0; i<l_s; i++)
    		if(!m[s[i]])
    			cout<<s[i];
    	memset(m, 0, 666*4);
		cout<<endl;
	}
    
	return 0;
}
