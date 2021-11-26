#include<bits/stdc++.h>
using namespace std;
int n,top=0,flag;
string s1,s2,name[1010],key[1010],hashkey[1010];
char c;
string hashit(string s){
	int len=s.length();
	int d1=len/4,d2=len/4,d3=len/4,d4=len/4;
	int ans=0;
	char s1[4];
	if(len%4==3)d1=d2=d3=d4+1;
	if(len%4==2)d1=d2=d4+1;
	if(len%4==1)d1=d4+1;
	
	ans=0;
	for(int i=0;i<d1;i++){
		if(isdigit(s[i]))ans+=s[i]-'0';
		else{
			if(s[i]-'a'>=0)s[i]-=32;
			ans+=s[i]-'A'+10;
			
		}ans%=36;
	}
	if(ans<=9)s1[0]=char(ans+'0');
	else s1[0]=char(ans-9+96);
	
	ans=0;
	for(int i=d1;i<d1+d2;i++){
		if(isdigit(s[i]))ans+=s[i]-'0';
		else{
			if(s[i]-'a'>=0)s[i]-=32;
			ans+=s[i]-'A'+10;
			
		}ans%=36;
	}
	if(ans<=9)s1[1]=char(ans+'0');
	else s1[1]=char(ans-9+96);
	
	ans=0;
	for(int i=d1+d2;i<d1+d2+d3;i++){
		if(isdigit(s[i]))ans+=s[i]-'0';
		else{
			if(s[i]-'a'>=0)s[i]-=32;
			ans+=s[i]-'A'+10;
			
		}ans%=36;
	}
	if(ans<=9)s1[2]=char(ans+'0');
	else s1[2]=char(ans-9+96);
	
	ans=0;
	for(int i=d1+d2+d3;i<d1+d2+d3+d4;i++){
		if(isdigit(s[i]))ans+=s[i]-'0';
		else{
			if(s[i]-'a'>=0)s[i]-=32;
			ans+=s[i]-'A'+10;
			
		}ans%=36;
	}
	if(ans<=9)s1[3]=char(ans+'0');
	else s1[3]=char(ans-9+96);
	
	return s1;
}
int main(){
	cin>>n;
	while(n--){
		cin>>c>>s1>>s2;
		if(c=='R'){
			flag=0;
			for(int i=1;i<=top;i++){
				if(s1==name[i]){
					flag=1;
					break;
				}
			}
			if(flag==1)printf("Repeated!");
			else{
				printf("Signed!");
				name[++top]=s1;
				key[top]=s2;
				hashkey[top]=hashit(s2);
			}
		}
		else{
			flag=0;
			for(int i=1;i<=top;i++){
				if(s1==name[i]&&s2==key[i]){
					printf("Success!");
					flag=1;
				}
				else if(s1==name[i]&&hashit(s2)==hashkey[i]){
					printf("Attention!");
					flag=1;
				}
			}
			if(flag==0)printf("Failed!");
		}
		printf("\n");
	}
	return 0;
}
