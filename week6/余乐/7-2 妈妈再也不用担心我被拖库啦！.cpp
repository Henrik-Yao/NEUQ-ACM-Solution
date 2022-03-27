#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1001
using namespace std;
typedef unsigned long long ull;
int t=0,n;
char id[101],pw[101],pass[N][101],a[5],b[5];
ull zid[N],zpw[N],base=131,prime=233317,mod=212370440130137957ll;
ull z_h(char a[]){
	int len=strlen(a);
 	ull ans=0;
 	for(int i=0;i<len;i++)
 		ans=(ans*base+(ull)a[i])%mod+prime;
 	return ans;
}
int y(int P){
	int len=strlen(pass[P]);
	int d=len/4,s=len-d*4,p=0;
	for(int i=1;i<=4;i++){
		int sum=0,S=0;
		if(s) S=1;
		for(int j=p;j<p+d+S;j++){
			char th=pass[P][j];
			if('0'<=th&&th<='9') sum+=th-'0';
			if('a'<=th&&th<='z') sum+=th-'a'+10;
			if('A'<=th&&th<='Z') sum+=th-'A'+10;
		}
		p=p+d+S;
		if(s) s--;
		sum%=36;
		if(sum<=9) a[i]=sum+'0';
		else a[i]=sum+'a'-10;
	}
	int len2=strlen(pw);
	int d2=len2/4,s2=len2-d2*4,p2=0;
	for(int i=1;i<=4;i++){
		int sum=0,S=0;
		if(s) S=1;
		for(int j=p2;j<p2+d2+S;j++){
			char th=pw[j];
			if('0'<=th&&th<='9') sum+=th-'0';
			if('a'<=th&&th<='z') sum+=th-'a'+10;
			if('A'<=th&&th<='Z') sum+=th-'A'+10;
		}
		p2=p2+d2+S;
		if(s2) s2--;
		sum%=36;
		if(sum<=9) b[i]=sum+'0';
		else b[i]=sum+'a'-10;
	}
	for(int i=1;i<=4;i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ac;cin>>ac;
		scanf("%s%s",id,pw);
		ull idz=z_h(id),pwz=z_h(pw);
		if(ac=='R'){
			bool pd=1;
			for(int j=0;j<t;j++)
				if(zid[j]==idz){
					pd=0;break;
				}
			if(pd){
				zid[t]=idz;
				int len=strlen(pw);
				for(int j=0;j<len;j++)
					pass[t][j]=pw[j];
				zpw[t++]=pwz;
				printf("Signed!");
			}
			else printf("Repeated!");
		}
		else{
			int p=-1;
			for(int j=0;j<t;j++)
				if(zid[j]==idz){
					p=j;break;
				}
			if(p==-1) printf("Failed!");
			else{
				if(pwz==zpw[p]) printf("Success!");
				else{
					if(y(p)) printf("Attention!");
					else printf("Failed!");
				}
			}
		}
		if(i<n) printf("\n");
	}
	return 0;
} 
