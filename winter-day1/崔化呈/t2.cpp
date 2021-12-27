#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str,s;
    getline(cin,str);
    int p=0,is=1;
    for(int i=0;i<str.size();i++)
    {
     	char c=str[i];
        if(c=='-'){is^=1;}
        else if(c=='['){p=0;}
        else if(c==']'){p=s.size();}
        else if(c=='{'){p=max(0,p-1);}
        else if(c=='}'){p=min((int)s.size(),p+1);}
        else if(c=='='){p=max(0,p-1);s.erase(p,1);}
          else
		  {
		  	if(is){s.insert(p,1,c);}
			else{s[p]=c;}
			p++;
			}  
        
    }
    cout<<s;
    return 0;
}
