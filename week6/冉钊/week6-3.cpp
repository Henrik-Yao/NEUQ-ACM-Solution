#include<bits/stdc++.h>
using namespace std;
string tex[10000],pat;
int num=1,ans=0;
int Next[1000010];
void getnext() {
	int i=0,j=1;
	Next[0]=-1;
	Next[1]=0;
	while(j<pat.size()) {
		if(i==-1||pat[i]==pat[j]) Next[++j]=++i;
		else {
			i=Next[i];
		}
		if(pat[j]==pat[Next[j]]) Next[j]=Next[Next[j]];
	}
}
int kmp(string tex) {
        int i=0,j=0;
        while(i<tex.size()){
         if(j==-1||tex[i]==pat[j]){
         	j++;
         	i++;
		 }
         else{
             j=Next[j];
         }
         if(j==pat.size()){
		  return 1;}//不用重置i和j，因为储存了next[j]也就是整个pat的next位置，下一次循环会自动更新j；
      }
    return 0;
}
int main() {
	char ch;
	while(ch=getchar()) {
		if(ch>='a'&&ch<='z') tex[num]+=ch;
		else if(ch>='A'&&ch<='Z') tex[num]+=ch+32;
		else if(ch=='\n'||ch=='\r') break;
		else if(tex[num].length()==0) continue;//注意其他字符是无限制输入的，但num只需要加一次； 
		else {
			num++;
		}
	}
	cin>>pat;
	for(int i=0;i<pat.size();i++)
	if(pat[i]<'a')
	pat[i]+=32;
	//处理pat中的大写字母； 
	getnext();
	for(int i=1; i<=num; i++) {
		if(kmp(tex[i])) ans++;
	}
	cout<<ans;
	return 0;
}