#include<bits/stdc++.h>
using namespace std;
set<string>setting;
map<string,string>mp;
char p;string user,mm;
int turn(char x);
int f(string s);
int Hash(string pw);
int main()
{
	int N;cin>>N;
	while(N--)
	{
		cin>>p>>user>>mm;
		if(p=='R')//当注册的时候 
		{
			int t=setting.size();//读入 
			setting.insert(user);
			if(setting.size()==t)//如果已经注册过了 
			{
				cout<<"Repeated!"<<endl;
			}
			else
			{
				mp.insert(pair<string,string>(user,mm));
				cout<<"Signed!"<<endl;
			}
		}
		else//登录 
		{
			if(mp.find(user)==mp.end())//用户不存在 
			{
				cout<<"Failed!"<<endl;
			}
			else
			{
				string ss=mp[user];
				if(mm==ss)//密码相同 
				{
					cout<<"Success!"<<endl;
				}
				else//密码不一样 
				{
					if(Hash(mm)==Hash(ss))//哈希值相等但密码不相同发生碰撞 
					{
						cout<<"Attention!"<<endl;
					}
					else
					{
						cout<<"Failed!"<<endl;
					}
				}
			}
		}	
	}
}
int turn(char x)//进行预处理 
{
	if(x>='0'&&x<='9')
	return x-'0';
	else if(x>='a'&&x<='z')
	return x-'a'+10;
	else if(x>='A'&&x<='Z')
	return x-'A'+10;
}
int f(string s)
{
	int total=0;
	for(int i=0;i<s.size();i++)
	{
		total+=turn(s[i]);
	}
	total%=36;
	return total;
	
}
int Hash(string pw)//进行哈希处理 
{
	string s1,s2,s3,s4;
	int len=pw.size();
	s4=pw.substr(len-len/4,len/4);
	int len4=s4.size();
	s3=pw.substr(len-len4-(len-len4)/3,(len-len4)/3);
	int len3=s3.size();
	s2=pw.substr(len-len4-len3-(len-len4-len3)/2,(len-len4-len3)/2);
	int len2=s2.size();
	s1=pw.substr(0,len-len4-len3-len2);
	int hash=f(s1)*36*36*36+f(s2)*36*36+f(s3)*36+f(s4);
	return hash;
}
