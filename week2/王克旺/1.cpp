#include<iostream>
#include<string>
using namespace std;
void ta(int n,string str1,string str2,string str3)
{
	if(n==1)
	{
		cout<<str1<<"->"<<str3<<endl;
	}
	else
	{
		ta(n-1,str1,str3,str2);
		cout<<str1<<"->"<<str3<<endl;
		ta(n-1,str2,str1,str3);
	}
} 
int main()
{
 	int n;
 	string str1,str2,str3;
 	cin>>n;
 	cin>>str1>>str2>>str3;
 	ta(n,str1,str2,str3);
 	return 0;
}
