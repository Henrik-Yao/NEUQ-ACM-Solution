#include<bits/stdc++.h>
using namespace std;
set<string>setting;
map<string,string>mp;
int turn(char x)
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
		//cout<<turn(s[i])<<' ';
		total+=turn(s[i]);
	}
	total%=36;
	//cout<<"total "<<total<<endl;
	return total;
	
}
int Hash(string pw)
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
	//cout<<s1<<' '<<s2<<' '<<s3<<' '<<s4<<endl;
	//cout<<f(s1)<<endl;
	int hash=f(s1)*36*36*36+f(s2)*36*36+f(s3)*36+f(s4);
	//cout<<hash<<endl;
	return hash;
}
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		char op;
		string user,pw;
		cin>>op>>user>>pw;
		if(op=='R')
		{
			int t=setting.size();
			setting.insert(user);
			if(setting.size()==t)
			{
				cout<<"Repeated!"<<endl;
				continue;
			}
			else
			{
				mp.insert(pair<string,string>(user,pw));
				cout<<"Signed!"<<endl;
			}
		}
		else
		{
			if(mp.find(user)==mp.end())
			{
				cout<<"Failed!"<<endl;
				continue;
			}
			else
			{
				string ss=mp[user];
				if(pw==ss)
				{
					cout<<"Success!"<<endl;
					continue;
				}
				else
				{
					if(Hash(pw)==Hash(ss))
					{
						cout<<"Attention!"<<endl;
						continue;
					}
					else
					{
						cout<<"Failed!"<<endl;
					}
				}
			}
		}	
	}
	return 0;
}
