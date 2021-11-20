#include <bits/stdc++.h>
using namespace std;
map<string,string>user;//定义一个用户的map
//map<string,string>Hash;//记录每一个字符串对应的哈希值
int len1,len2,len3,len4;//临时记录其四个小字符串的长度
string runhash(string code) {
	int len=code.size();
	int remp=len%4;
	switch(remp) {
		case 0: {
			len1=len2=len3=len4=len/4;
			break;
		}
		case 1: {
			len1=len/4+1;
			len2=len3=len4=len/4;
			break;
		}
		case 2: {
			len1=len2=len/4+1;
			len3=len4=len/4;
			break;
		}
		case 3: {
			len1=len2=len3=len/4+1;
			len4=len/4;
			break;
		}//记录其字符串分配情况
	}
	//for(i=0;i<temp;++i) len[i]=n/4+1;
	//for(int i=temp;i<4;++i) len[i]=n/4;
	 
	int sum[5]= {0,0,0,0,0}; //记录hash
	for(int i=0; i<len1; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]-'A'+'a';//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-'a'+10;
			sum[1]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-'0';
			sum[1]+=shu;
		}
	}
	for(int i=len1; i<len1+len2; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[2]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[2]+=shu;
		}
	}
	for(int i=len1+len2; i<len1+len2+len3; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[3]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[3]+=shu;
		}
	}
	for(int i=len1+len2+len3; i<len1+len2+len3+len4; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[4]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[4]+=shu;
		}
	}
	for(int i=1; i<=4; i++) {
		sum[i]=sum[i]%36;
	}
	string zan;
	for(int i=0; i<4; i++) {
		char ch;
		if(sum[i+1]<=9&&sum[i+1]>=0) {
			ch=sum[i+1]+'0';
//			zan[i]=ch;
			zan+=ch; 
		}
		if(sum[i+1]<=36&&sum[i+1]>9) {
			ch=sum[i+1]-10+'a';
//			zan[i]=ch;
			zan+=ch; 
		}
	} 
	return zan;
}
int main() {
	int num;
	cin>>num;
	for(int i=0; i<num; i++) {
		char ch;
		cin>>ch;
		string str;//用户名
		string remp;//用户密码
		cin>>str;
		cin>>remp;
		if(ch=='R') {
//			string a=user[str];
			if(user.count(str))//count测其中有没有东西 
				cout<<"Repeated!";//之前已经注册过
			else {
				user[str]=remp;//若无注册过，将该元素存入map中
				cout<<"Signed!";
//				Hash[str]=runhash(remp);//对其密码进行规划
			}
		}
		if(ch=='L') {
//			string de=runhash(remp);//登录密码的哈希代码
//			string zh=Hash[str];//该用户的哈希代码
//			string mi=user[str];//该用户的原密码
			if(user[str]==remp) {
				cout<<"Success!";
			} else if(runhash(user[str])==runhash(remp)) {
//				cout<<user[str]<<" "<<remp<<"\n";
				cout<<"Attention!";
			} else {
				cout<<"Failed!";
			}
		}
		cout<<"\n"; 
	}
	
	return 0;
}
