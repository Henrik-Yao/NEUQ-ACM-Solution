#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<char>s;
int main()
{	
    int flag=1;
	char str[10000];
    cin>>str;
    int length=strlen(str);
    for(int i=0;i<length;i++)
    {
        if(str[i]!='('&&str[i]!=')'&&str[i]!='['&&str[i]!=']'&&str[i]!='{'&&str[i]!='}')
        {
        	continue;
		}
        if(str[i]=='('||str[i]=='['||str[i]=='{')
        {
        	s.push(str[i]);
		}    
        else if((str[i]==')'&&s.top()=='(')||(str[i]==']'&&s.top()=='[')||(str[i]=='}'&&s.top()=='{'))
        {
        	s.pop();
		}       
        if((i==length-1&&s.size()!=0)||(i!=length-1&&s.size()==0))
        {
        	flag=0;
		}
    }
    if(flag==1)
    {
    	cout<<"yes";
	}     
    else
    {
    	cout<<"no";
	}
	return 0;
}
