#include <bits/stdc++.h>
using namespace std;
int i=0;
bool flag=true;
int f=0;
struct hp{
	char p;//L or R 
	string nam;//�û��� 
	string pw;//���� 
	string hax;//��ϣֵ 
} zh[10001];
map<string,pair<string,string> > mp;//ʹ��map,��һ�����û������ڶ���pair�������뼰���Ӧ�Ĺ�ϣ 
char get_hash(string str)//����һС�ڵĹ�ϣֵ 
{
	int haxi=0,l=str.length();
	for(int j=0;j<l;j++)//length()������������ 
	{
		if(str[j]>='A'&&str[j]<='Z') str[j]=str[j]|32;
		if(str[j]>='0'&&str[j]<='9') haxi+=str[j]-'0';
		else haxi+=str[j]-'a'+10;
	}
	haxi=haxi%36;
	if(haxi<10) return haxi+'0';
	else return haxi+'a'-10;//a����10 
}
string Hash(string w)//����һ������Ĺ�ϣֵ,hash�ǹؼ��� 
{
	int le=w.length(),mo=le%4,l[5]={0},j=0;
	while(mo--) l[j++]++;
	j=0;
	string h="0000";
	for(int p=0;p<4;p++)
	{
		l[p]=l[p]+le/4;
		string str=w.substr(j,l[p]);
		j+=l[p];
		h[p]=get_hash(str);
	}
	return h;
}
void zhuce(string name,string password,string hax)//ע����� 
{
	if(mp.find(zh[i].nam)!=mp.end())cout<<"Repeated!"<<endl;
			else {
				mp[zh[i].nam].first=zh[i].pw;
				mp[zh[i].nam].second=zh[i].hax;
				cout<<"Signed!"<<endl;
			}
}
void denglu(string name,string password,string hax)//��½���� 
{
	if(mp.find(zh[i].nam)==mp.end())
	{
		cout<<"Failed!"<<endl;
	}
	else
	{
		if(mp.find(zh[i].nam)->second.first==zh[i].pw) cout<<"Success!"<<endl;
		else
		{
			if(mp.find(zh[i].nam)->second.second==zh[i].hax) cout<<"Attention!"<<endl;
			else cout<<"Failed!"<<endl;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int z=0;z<n;z++)
	{
		cin>>zh[i].p>>zh[i].nam>>zh[i].pw;
		zh[i].hax=Hash(zh[i].pw);
		cout<<zh[i].hax<<endl;
		if(zh[i].p=='R') zhuce(zh[i].nam,zh[i].pw,zh[i].hax);
		else denglu(zh[i].nam,zh[i].pw,zh[i].hax);
	}
	return 0;
}
