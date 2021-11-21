#include <bits/stdc++.h>
using namespace std;
int i=0;
bool flag=true;
int f=0;
struct hp{
	char p;//L or R 
	string nam;//用户名 
	string pw;//密码 
	string hax;//哈希值 
} zh[10001];
map<string,pair<string,string> > mp;//使用map,第一个是用户名，第二个pair包含密码及其对应的哈希 
char get_hash(string str)//计算一小节的哈希值 
{
	int haxi=0,l=str.length();
	for(int j=0;j<l;j++)//length()不能用作条件 
	{
		if(str[j]>='A'&&str[j]<='Z') str[j]=str[j]|32;
		if(str[j]>='0'&&str[j]<='9') haxi+=str[j]-'0';
		else haxi+=str[j]-'a'+10;
	}
	haxi=haxi%36;
	if(haxi<10) return haxi+'0';
	else return haxi+'a'-10;//a代表10 
}
string Hash(string w)//计算一条密码的哈希值,hash是关键词 
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
void zhuce(string name,string password,string hax)//注册操作 
{
	if(mp.find(zh[i].nam)!=mp.end())cout<<"Repeated!"<<endl;
			else {
				mp[zh[i].nam].first=zh[i].pw;
				mp[zh[i].nam].second=zh[i].hax;
				cout<<"Signed!"<<endl;
			}
}
void denglu(string name,string password,string hax)//登陆操作 
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
