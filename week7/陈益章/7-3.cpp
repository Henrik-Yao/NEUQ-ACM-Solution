#include<iostream>
#include<cstring>
using namespace std;
int cunt[256];
int main()
{
	string str1,str2;
	while (	getline(cin,str1)&&getline(cin,str2))
	{
		memset(cunt,0,sizeof(cunt));
	for (int i=0;i<str1.length();i++)
	cunt[str1[i]]++;
	for (int i=0;i<str2.length();i++)
	cunt[str2[i]]=0;
	for (int i=0;i<str1.length();i++)
	if (cunt[str1[i]]!=0)
	cout<<str1[i];
	cout<<endl;
		string str1,str2;
}
}
