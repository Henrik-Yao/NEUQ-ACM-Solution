#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;

struct people{
	char sex;
	string father;
};

map<string,people> mp;

int panduan(string a,string b){
	int i=1,j;
	for(string aa=a; !aa.empty(); aa = mp[aa].father,i++){
		j = 1;
		for(string bb=b; !bb.empty(); bb=mp[bb].father,j++){	//���ԱȽ���� 
			if(i >= 5 && j >= 5)	//�����û�У��Ϳ��Խ��� 
				return 1;
			if(aa == bb && (i<5 || j<5))	//����ڳ�����ͬ���ȣ����ɽ��� 
				return 0;
		}
	}
	return 1;	//�����������û�й�ͬ���ȣ��ɽ��� 
}

int main(){
	int n;
	cin.sync_with_stdio(false);	//��䲻���٣�Ҫ��Ȼ���г�ʱ
	cin >> n;
	string a,b;
	for(int i=0; i < n; i++){
		cin >> a >> b;
		if(b.back() == 'r'){	//ά��Ů�� 
			mp[a] = {'f',b.substr(0,b.size()-7)};	//���׵�������Ů�����գ�ȥ��"sdottir" 
		}
		else if(b.back() == 'n') {	//ά������ 
			mp[a] = {'m',b.substr(0,b.size()-4)};	//���׵��������������գ�ȥ��"sson" 
		}
		else{	//���Ǳ��صģ�ֱ�������һλ�ж��Ա𣬲���Ҫ֪������ 
			mp[a].sex = b.back();
		}
	}
	
	int m;
	cin >> m;
	string str;
	for(int i=0; i < m; i++){
		cin >> a >> str >> b >> str;
		if(mp.find(a) == mp.end() || mp.find(b) == mp.end())	//���Ƿ���һ������������ 
			printf("NA\n");
		else if(mp[a].sex == mp[b].sex)	//�ж��Ƿ�ͬ�� 
			printf("Whatever\n");
		else 
			printf("%s\n", panduan(a, b) ? "Yes" : "No");
	}
}

