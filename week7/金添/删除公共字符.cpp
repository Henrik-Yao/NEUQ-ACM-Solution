#include <bits/stdc++.h>
using namespace std;
string tar;//Ŀ��
string str;//ģʽ��
//int len1;//Ŀ�곤��
//int len2;//ģʽ������
//map<char,bool>judge;//�ж��Ƿ��ظ�
int main() {
	while(getline(cin,tar)&&getline(cin,str)) {
		
		map<char,bool>judge;
		int len1=tar.size();
		int len2=str.size();
		for(int i=0; i<len2; i++) {
			judge[str[i]]=1;//�ظ�Ԫ�ر��
		}
		for(int i=0; i<len1; i++) {
			char ch=tar[i];
			if(judge[ch]) continue;
			cout<<tar[i];
		}
		cout<<endl;
	}
	return 0;
}
