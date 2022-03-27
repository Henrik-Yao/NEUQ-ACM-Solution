#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string stri;
	getline(cin, stri);
	int sm=0, mi=0, bi=0;
	for(int i=0; stri[i]!='\0'; i++)
	{
		switch(stri[i])
		{
			case '(':	sm+=1;	break;
			case ')':	sm-=1;	break;
			case '[':	mi+=1;	break;
			case ']':	mi-=1;	break;
			case '{':	bi+=1;	break;
			case '}':	bi-=1;	break;
		}
		if((sm<0)||(mi<0)||(bi<0))
		{
			cout<<"no";
			return 0;
		}
	}
	if((sm!=0)||(mi!=0)||(bi!=0))	cout<<"no";
	else	cout<<"yes";
	return 0;
}
