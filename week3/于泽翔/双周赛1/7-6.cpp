#include <bits/stdc++.h>
using namespace std;
char s[11];
int main(void)
{
	cin>>s;
    int n=strlen(s);
    sort(s, s+n);
    
    do
        cout<<s<<endl;
    while(next_permutation(s, s+n));
	
	return 0;
}