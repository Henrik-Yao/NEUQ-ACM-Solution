#include <bits/stdc++.h>
using namespace std;
string tar;//目标
string str;//模式串
//int len1;//目标长度
//int len2;//模式串长度
//map<char,bool>judge;//判断是否重复
int main() {
	while(getline(cin,tar)&&getline(cin,str)) {
		
		map<char,bool>judge;
		int len1=tar.size();
		int len2=str.size();
		for(int i=0; i<len2; i++) {
			judge[str[i]]=1;//重复元素标记
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
