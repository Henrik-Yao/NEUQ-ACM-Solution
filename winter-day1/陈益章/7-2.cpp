#include<iostream>
#include<cstring>
#include<vector> 
using namespace std;
vector<char> chain;
int main()
{
	int pointer=0,i=0,n=0;
	bool isrpl=0; 
	string str,temp;
	getline(cin,str);
	for (int i=0;i<str.length();i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			if(isrpl==1)
			{
				chain[pointer]=str[i];
				pointer++;
				continue;
			}
		chain.insert(chain.begin()+pointer,str[i]);
		pointer++; 
		} 
		if(str[i]>='A'&&str[i]<='Z')
		{
			if(isrpl==1)
			{
				chain[pointer]=str[i];
				continue;
			}
		chain.insert(chain.begin()+pointer,str[i]);
		pointer++; 
		} 
		if(str[i]==' ')
		{
			if(isrpl==1)
			{
				chain[pointer]=str[i];
				continue;
			}
		chain.insert(chain.begin()+pointer,str[i]);
		pointer++; 
		} 
		if(str[i]=='[')
		pointer=0;
		if(str[i]==']')
		pointer=chain.size();
		if(str[i]=='{')
		{
		if(pointer>0)
		pointer--;
		}
		if(str[i]=='}')
		{
		if(pointer<chain.size()-n)
		pointer++;
		}
		if(str[i]==45)
		{
		if(isrpl==0)
		isrpl=1;
		else
		{
			isrpl=0;
		}
		}
		if(str[i]=='=')
		{
		chain.erase(chain.begin()+pointer,chain.begin()+pointer);
		pointer--;
		n++;
		} 
	}
	for (int i=0;i<chain.size()-n;i++)
	cout<<chain[i];
	cout<<endl;
}
