#include<bits/stdc++.h>
using namespace std;
int i,len = 0;
int first=0,ennd=0,d;
string s;
int main()
{   cin>>s;
    for(i=0;s[i]!='#';i++)
	{
        len++;
    }
    for(i=0;i<len;i++)
	{
       if(s[i]=='(')
	   {
            first=i;
          }else if(s[i]==')')
		  {
              ennd=i;
          }

    }
    for(i=0;i<len;i++)
	{
        if(s[i]=='A')
		{
            cout << "sae";
        }
		else if(s[i] == 'B')
		{
            cout << "tsaedsae";
        }
		else if(s[i] == '(')
		{
           cout << s[i+1];
           for(d=ennd-1;d>first+1;d--)
		   {
            cout<<s[d]<<s[i+1];
           }
           i=ennd;
        }

}
 
}

