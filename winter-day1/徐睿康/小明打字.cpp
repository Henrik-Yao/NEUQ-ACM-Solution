#include<bits/stdc++.h>
using namespace std;
vector<char>a;
string s;
int len,i,cnt=0,flag=1;
int main(){
	//while(1){
		getline(cin,s);
		len=s.length();
		i=0;
		for(int j=0;j<len;j++){
			if(s[j]=='[')i=0;
			if(s[j]==']')i=cnt;
			if(s[j]=='{')i--;
			if(s[j]=='}')i++;
			if(s[j]=='-')flag=-flag;
			if(s[j]=='='){
				a.erase(a.begin()+i-1);
				i--;
				cnt--;
				
			}
			if(isalpha(s[j])||s[j]==' '){
				if(flag<0){
					a.erase(a.begin()+i);
					cnt--;
					if(cnt<0)cnt=0;
				}
				a.insert(a.begin()+i,s[j]);
				i++;
				cnt++;
			}
			if(i<0)i=0;
			if(i>cnt)i=cnt;
			if(cnt<0)cnt=0;
		}
		for(int i=0;i<cnt;i++)cout<<a[i];
		//cout<<endl;
	//}
	return 0;
}
