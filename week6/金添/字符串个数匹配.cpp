#include <bits/stdc++.h>
using namespace std;
char tar[1000000];//记录主串
char ch[1000000];//记录模式串
int next1[1000000];
int	length[1000001];//记录各个小字符串的长度
int num=0;//记录总共小字符串的个数
int cou=0;//记录KMP搜索时进行到哪个小字符串
long long sum=0;
int sen=0;
void getnext() { //求模式串的next值
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
	int remp1=0;//主串指针
	int remp2=0;//模式串指针
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
	/*	         分割线                    */
	for(int i=0; i<l1; i++) {
		if(tar[i]<='Z'&&tar[i]>='A')
			tar[i]=tar[i]+32;
		if(!((tar[i]<='z'&&tar[i]>='a')))
			tar[i]=' ';
	}
	/*	         分割线                    */
	for(int i=0; i<l1; i++) {
		if((tar[i]>='a'&&tar[i]<='z')&&(!(tar[i+1]>='a'&&tar[i+1]<='z')))
			length[num++]=i+1;
	}
	/*	         分割线                    */
	getnext();
	cout<<KMP();
	return 0;
}
