#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string a;
int lena; 
void yl(int l,int r){
	if(l>r) return;
	if(a[l]!='['){
		printf("%c",a[l]);
		yl(l+1,r);
	}
	else{
		int s,L,t,I=a[l+1]-'0';
		if('0'<=a[l+2]&&a[l+2]<='9')
			I=I*10+a[l+2]-'0';
		for(int i=1;i<=I;i++){
			s=0;t=l+2,L=l+2;
			if(I>=10) t++,L++;
			while(t<=r-1){
				if(a[t]=='[') s++;
				if(a[t]==']') s--;
				if(s<0) break;
				if(s==0){
					yl(L,t);
					L=t+1;
				}
				t++;
			}
		}
		if(s<0) yl(t+1,r);
	}
}
int main(){
	cin>>a;
	lena=a.size();
	yl(0,lena-1);
	return 0;
}
