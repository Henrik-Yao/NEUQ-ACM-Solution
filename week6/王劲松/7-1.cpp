#include<bits/stdc++.h>
using namespace std;
int main(){
	int j,k,n1,n2,cnt=0;
	string s1,s2;
	cin>>s1>>s2;
	n1=s1.size() ,n2=s2.size();
	s2[n2]='*',n2++;
	int next[100000];
	next[0]=-1;
	for(j=0,k=-1;j<s2.size();){
		if(k==-1||s2[j]==s2[k])next[++j]=++k;//从第二位和第一位开始比较、、当K指向开头（k==-1），++j的匹配失败移动0； 
		else k=next[k]; 					 //当K不指向开头且j,k比较出不同让k指向开头 
	}
	for(j=0,k=0;j<n1;){
		if(s1[j]==s2[k]){
			if(k==n2-2)cnt++;
			k++,j++;
		}
		else if(next[k]==-1)k=0,j++;
		else k=next[k];
	}
	cout<<cnt<<endl;
	return 0;
}
