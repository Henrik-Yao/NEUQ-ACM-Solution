#include<bits/stdc++.h>
using namespace std;
int len;
string str;
void zhankai(int i)
{
	string charu;
	int zuo=1;
	int bei=0;
	int w;
	for(w=1;w<100;w++)
	if(str[i+w]>='0'&&str[i+w]<='9')
	{
		bei*=10;
		bei+=str[i+w]-'0';
	}
	else break;
	int begin=i;
	for(i+=w;zuo;i++)
	{
		if(str[i]==']') zuo--;
		else if(str[i]=='[') zuo++;
	}
	int q=begin;
	for(begin+=w;begin<i-1;begin++) charu+=str[begin];
	str.erase(q,i-q);
	for(int j=0;j<bei;j++) str.insert(q,charu);
}
int main()
{
	cin>>str;
	len=str.length();
	for(int i=0;i<len;i++)
	{
		if(str[i]=='[') 
		{
			zhankai(i);
			len=str.length();	
			i--;		
		}
				
	}
	cout<<str;
	return 0;
}