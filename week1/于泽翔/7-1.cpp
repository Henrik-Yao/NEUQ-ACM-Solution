#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m, ass, l_s, l_a;
    char s[55000], a[44];
    cin>>n;
    cin>>s;
    l_s=strlen(s);
    while(n--)
    {
        m=0;
        cin>>a;
        l_a=strlen(a);
        
        for(int i=0; i<=l_s-l_a; i++)
        {
            ass=1;
            for(int j=0; j<l_a; j++)
            {
            	if(s[i+j]!=a[j])
                {
                    ass=0;
                    break;
                }
			}
            if(ass)
            	m++;
        }
        
        cout<<m;
        if(n)
            cout<<endl;
    }
	
	return 0;
}