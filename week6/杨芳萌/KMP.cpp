#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int n,m,nxt[N],cnt;
char a[N],p[N];
void get_nxt() {
	for(int i=2,j=0; i<=n; i++) {
		while(j && p[i]!=p[j+1]) j = nxt[j];
		if(p[i]==p[j+1]) j++;
		nxt[i] = j;
	}
}
void kmp() {
	for(int i=1,j=0; i<=m; i++) {
		while(j && a[i]!=p[j+1]) j = nxt[j];
		if(a[i]==p[j+1]) j++;
		if(j==n) {
			j = nxt[j];
//			printf("%d ",i-n);
			cnt++;
		}
	}
}
int main() {
	cin>>a+1>>p+1;
	m = strlen(a+1);//ԭ�ַ������� 
	n = strlen(p+1);//Ҫ�ҵ��ַ������� 
	get_nxt();
	kmp();
	cout<<cnt<<endl;
	return 0;
}//nxt[j] ��ʾp[1,j] = p[i-j+1,i]
