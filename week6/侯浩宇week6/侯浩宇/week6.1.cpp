#include<bits/stdc++.h>
using namespace std;
char s[1000005],p[1000005];
int Next[1000005];
void GetNext(int p1){
	int k=-1;
	Next[0]=-1;
	int j=0;
	while(j<p1){
		if(k==-1||p[j]==p[k]){
			j++;
			k++;
			Next[j]=k;
		}else {
			k=Next[k];
		}
	}
}
int KMP(int s1,int p1){
	int i=0;
	int j=0;
	int cnt=0;
	while(i<s1&&j<p1){
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
		}else{
			j=Next[j];
		}
		if(j==p1)cnt++,j=Next[j-1],i--;
	}
	return cnt; 
}
int main(){
	int s1,p1;
	for(s1=0;(s[s1]=getchar())!='\n';s1++);
	for(p1=0;(p[p1]=getchar())!='\n';p1++);
	GetNext(p1);
	cout<<KMP(s1,p1);
}
