#include<iostream>
#include<string>
using namespace std;
//AB[3BC[2XY]]
int i=0;//i代替指针，从0位开始读
string s;
int readnum()//该重所要的乘的数
{
	i++;//读下一位
	int t=0;
	while(s[i]>='0'&&s[i]<='9')//指的为数字
	{
		t=t*10+((int)s[i]-48);
		i++;
	}
	return t;//返回
}
string f()
{
	int n=1;
	string s1,s2;
	while(s[i]!='\0')
	{
		if(s[i]=='[')
		{
			n=readnum();//读数字
			s2=f();
			while(n--) s1+=s2;
		}
		else
		{
			if(s[i]==']') return s1;//返回子串
			else s1+=s[i];
		}
		i++;//读下一位
	}
}
int main()
{
	getline(cin,s);
	cout<<f();
	return 0;	
}
