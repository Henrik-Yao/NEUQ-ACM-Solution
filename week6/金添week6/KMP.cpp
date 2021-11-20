#include <bits/stdc++.h>
using namespace std;
char tar[1000000];//记录主串
char ch[1000000];//记录模式串
int next1[1000000];
long long sum=0;
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
		if(remp2==-1||tar[remp1]==ch[remp2]) {
			remp1++;
			remp2++;
		} else {
			remp2=next1[remp2];
		}
		
		if(jt==remp2) {
			sum++;
			remp2=next1[remp2];
		}
	}
	return sum;
}
int main() {
	cin>>tar;
	cin>>ch;
	getnext();
	cout<<KMP();
	return 0;
}
