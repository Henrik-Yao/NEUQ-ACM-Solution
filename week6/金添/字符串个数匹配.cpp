#include <bits/stdc++.h>
using namespace std;
char tar[1000000];//��¼����
char ch[1000000];//��¼ģʽ��
int next1[1000000];
int	length[1000001];//��¼����С�ַ����ĳ���
int num=0;//��¼�ܹ�С�ַ����ĸ���
int cou=0;//��¼KMP����ʱ���е��ĸ�С�ַ���
long long sum=0;
int sen=0;
void getnext() { //��ģʽ����nextֵ
	int remp1,remp2;
	remp1=-1;
	remp2=0;
	next1[0]=-1;
	int jtdsb=strlen(ch);
	while(remp2<jtdsb) {
		if(remp1==-1||ch[remp1]==ch[remp2]) {
			next1[++remp2]=++remp1;
		} else {
			remp1=next1[remp1];
		}
	}
}
int KMP() {
	int remp1=0;//����ָ��
	int remp2=0;//ģʽ��ָ��
	int jtdsb=strlen(tar);
	int jt=strlen(ch);
	while(remp1<jtdsb) {
		if(remp1<length[cou]) {
			if(remp2==-1||tar[remp1]==ch[remp2]) {
				remp1++;
				remp2++;
			} else {
				remp2=next1[remp2];
			}

			if(jt==remp2) {
				sum++;
				remp2=next1[remp2];
				remp1=length[cou];
				cou++;
				sen++;
			}
		} 
			else {
			remp1=length[cou];
			cou++;
			}
	}
	return sen;
}
int main() {
	cin.getline(tar,1000000000);
	cin.getline(ch,10000);
	int l1=strlen(tar);
	int l2=strlen(ch);
	for(int i=0; i<l2; i++) {
		if(ch[i]<='Z'&&ch[i]>='A')
			ch[i]=ch[i]+32;
	}
	/*	         �ָ���                    */
	for(int i=0; i<l1; i++) {
		if(tar[i]<='Z'&&tar[i]>='A')
			tar[i]=tar[i]+32;
		if(!((tar[i]<='z'&&tar[i]>='a')))
			tar[i]=' ';
	}
	/*	         �ָ���                    */
	for(int i=0; i<l1; i++) {
		if((tar[i]>='a'&&tar[i]<='z')&&(!(tar[i+1]>='a'&&tar[i+1]<='z')))
			length[num++]=i+1;
	}
	/*	         �ָ���                    */
	getnext();
	cout<<KMP();
	return 0;
}
