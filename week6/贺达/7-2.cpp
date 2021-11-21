#include<bits/stdc++.h>
using namespace std;
struct Node{
	string c; //操作符
	string zh; //账号
	string mm; //密码
	string hx; //哈希值
};
int n;
Node node[1002];
map<string,pair<string,string> > mp;//已注册账号信息存储，map中第一个参数为账号，第二个参数为pair型，pair中第一个参数为密码，第二个参数为密码对应的哈希值。
char getHash(string str){ //计算字串的哈希值，返回一个字符char
	int sum=0;
	int ls=str.length();
	for(int i=0;i<ls;i++){
		if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]+'a'-'A';
		if(str[i]>='0'&&str[i]<='9'){
			sum+=str[i]-'0';
		}else{
			sum+=str[i]-'a'+10;
		}
	}
	sum=sum%36;
	if(sum<10) return sum+'0';
	else return sum-10+'a';
}
string Hash(string str){ //计算密码的哈希值，返回四位字符串
	string hx="0000";
	int l=str.length();
	int index[5]={0};
	//分配4位
	for(int i=0;i<l%4;i++){
		index[i]++;
	}
	//分别计算四个子字符串的哈希值
	int j=0;
	for(int i=0;i<4;i++){
		index[i]= index[i]+l/4;
		string str1=str.substr(j,index[i]);//截取子字符串
		j+=index[i];
		char h=getHash(str1);
		hx[i]=h;
	}
	return hx;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>node[i].c>>node[i].zh>>node[i].mm;
		node[i].hx=Hash(node[i].mm);
		if(node[i].c=="R")
            {
			if(mp.find(node[i].zh)!=mp.end())cout<<"Repeated!"<<endl;
			else
            {
				mp[node[i].zh].first=node[i].mm;
				mp[node[i].zh].second=node[i].hx;
				cout<<"Signed!"<<endl;
			}
		}
		else if(node[i].c=="L")
		{
			if(mp.find(node[i].zh)==mp.end())
			{
				cout<<"Failed!"<<endl;
			}
            else
            {
				if(mp.find(node[i].zh)->second.first==node[i].mm) cout<<"Success!"<<endl;
				else{

					if(mp.find(node[i].zh)->second.second==node[i].hx)cout<<"Attention!"<<endl;
					else cout<<"Failed!"<<endl;
				}
			}
		}
	}
	return 0;
}
