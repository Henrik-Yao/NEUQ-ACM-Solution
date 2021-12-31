#include <bits/stdc++.h>
using namespace std;
map<string,string>user;//����һ���û���map
//map<string,string>Hash;//��¼ÿһ���ַ�����Ӧ�Ĺ�ϣֵ
int len1,len2,len3,len4;//��ʱ��¼���ĸ�С�ַ����ĳ���
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
		}//��¼���ַ����������
	}
	//for(i=0;i<temp;++i) len[i]=n/4+1;
	//for(int i=temp;i<4;++i) len[i]=n/4;
	 
	int sum[5]= {0,0,0,0,0}; //��¼hash
	for(int i=0; i<len1; i++) { //��ʼ�ֲ������ϣֵ

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]-'A'+'a';//ת��ΪСд
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
	for(int i=len1; i<len1+len2; i++) { //��ʼ�ֲ������ϣֵ

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//ת��ΪСд
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
	for(int i=len1+len2; i<len1+len2+len3; i++) { //��ʼ�ֲ������ϣֵ

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//ת��ΪСд
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
	for(int i=len1+len2+len3; i<len1+len2+len3+len4; i++) { //��ʼ�ֲ������ϣֵ

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//ת��ΪСд
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
		string str;//�û���
		string remp;//�û�����
		cin>>str;
		cin>>remp;
		if(ch=='R') {
//			string a=user[str];
			if(user.count(str))//count��������û�ж��� 
				cout<<"Repeated!";//֮ǰ�Ѿ�ע���
			else {
				user[str]=remp;//����ע���������Ԫ�ش���map��
				cout<<"Signed!";
//				Hash[str]=runhash(remp);//����������й滮
			}
		}
		if(ch=='L') {
//			string de=runhash(remp);//��¼����Ĺ�ϣ����
//			string zh=Hash[str];//���û��Ĺ�ϣ����
//			string mi=user[str];//���û���ԭ����
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
