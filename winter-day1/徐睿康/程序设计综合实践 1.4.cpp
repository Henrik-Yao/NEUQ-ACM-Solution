#include<bits/stdc++.h>
using namespace std;
string s;
int len,a[10000010],cnt=0,sum=0,flag;
int main(){
	getline(cin,s);
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]!=' '){
			sum*=10;
			sum+=s[i]-'0';
		}
		else{
			if(s[i-1]==' ')continue;
			a[++cnt]=sum;
			sum=0;
		}
	}
	a[++cnt]=sum;
	sort(a+1,a+cnt+1);
	for(int i=1;i<=cnt;i++){
		if(i==1)cout<<a[i];
		else cout<<"->"<<a[i];
	}
	cout<<endl;
	flag=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]%2==0)continue;
		else{
			if(flag==0){
				flag=1;
				cout<<a[i];
			}
			else{
				cout<<"->"<<a[i];
			}
		}
	}
	cout<<endl;
	flag=0;
	for(int i=1;i<=cnt;i++){
		if(a[i]%2==0){
			if(flag==0){
				flag=1;
				cout<<a[i];
			}
			else{
				cout<<"->"<<a[i];
			}
		}
	}
	return 0;
}
