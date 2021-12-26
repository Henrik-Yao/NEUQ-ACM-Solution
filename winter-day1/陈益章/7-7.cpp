#include<iostream>
#include<string>
using namespace std;
int main()
{
	char c;
	string str="",temp="";
	while(cin>>c)
	{
		if(c=='#') break;
		else if(c<='z' && c>='a')
		{
			str=str+c;
		}
		else if(c=='A')
		{
			
			str=str+"sae";
		}
		else if(c=='B')
		
		{
			str=str+"tsaedsae";
		}
		else if(c=='(')
		{
			
			while(cin>>c)
			{
				if(c==')') break;
				temp=temp+c;
			}
			
			char thita=temp[0];
			for(int j=temp.size()-1;j>0;j--)
			{
				str=str+thita+temp[j];
			}
			str=str+thita;
		}	
	}
	cout<<str;
    cout<<endl;
}
