#include <bits/stdc++.h>
using namespace std;
string change(int begin,string str)
{
	int leng=0;
	string chang;
	for(int i=begin;;i++)
	{
		if(str[i]==')') break;
		leng++;
	}
	for(int i=leng-1;i>0;i--)
	{
		chang+=str[begin];
		chang+=str[begin+i];
	}
	chang+=str[begin];
	str.replace(begin-1,leng+2,chang);
	return str;
}
int main()
{
	string str;
	cin>>str;
	int i=0;
	while(str[i]!='\0'&&((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||str[i]=='('||str[i]==')'))
	{
		if(str[i]=='A') 
		{
			str.replace(i,1,"sae");
			i+=2;
		}
		else if(str[i]=='B') 
		{
			str.replace(i,1,"tsaedsae"); 
			i+=7;
		}
		else if(str[i]=='(')
		{
			str=change(i+1,str);
			i--;
		}
		i++;
	}
	str.erase(i,str.length());
	cout<<str;
	return 0;
}
