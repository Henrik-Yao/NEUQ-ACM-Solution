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
		if(p=='R')//��ע���ʱ�� 
		{
			int t=setting.size();//���� 
			setting.insert(user);
			if(setting.size()==t)//����Ѿ�ע����� 
			{
				cout<<"Repeated!"<<endl;
			}
			else
			{
				mp.insert(pair<string,string>(user,mm));
				cout<<"Signed!"<<endl;
			}
		}
		else//��¼ 
		{
			if(mp.find(user)==mp.end())//�û������� 
			{
				cout<<"Failed!"<<endl;
			}
			else
			{
				string ss=mp[user];
				if(mm==ss)//������ͬ 
				{
					cout<<"Success!"<<endl;
				}
				else//���벻һ�� 
				{
					if(Hash(mm)==Hash(ss))//��ϣֵ��ȵ����벻��ͬ������ײ 
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
int turn(char x)//����Ԥ���� 
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
int Hash(string pw)//���й�ϣ���� 
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
