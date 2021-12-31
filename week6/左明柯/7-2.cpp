#include <bits/stdc++.h>
using namespace std;
map<string,string>node;
int gethash(string a){
	int l=a.length();int m[12000];
	for(int i=0;i<l;i++){
		if(a[i]>='A'&&a[i]<='Z') m[i]=a[i]-'A'+10;
		if(a[i]>='a'&&a[i]<='z') m[i]=a[i]-'a'+10;
		if(a[i]>='0'&&a[i]<='9') m[i]=a[i]-'0';}
		int mod=l%4;int a0,a1,a2,a3;
		a0=0;a1=0;a2=0;a3=0;
		int x[4];
		for(int i=0,j=mod;i<4;i++,j--){
			if(j>0) x[i]=l/4+1;
			else x[i]=l/4;
			if(i)x[i]+=x[i-1];
		}
	
		for(int i=0;i<x[0];i++){a0+=m[i];a0%=36;}
	    for(int i=x[0];i<x[1];i++){a1+=m[i];a1%=36;}
	    for(int i=x[1];i<x[2];i++){a2+=m[i];a2%=36;}
	    for(int i=x[2];i<x[3];i++){a3+=m[i];a3%=36;}
		
	return ((a0*36+a1)*36+a2)*36+a3;
}
int main(){
int n;
cin>>n;
while(n--){
	char op;
	string name,key;
	cin>>op>>name>>key;
	if(op=='R'){
		if(node[name]==""){
		node[name]=key;cout<<"Signed!\n";
		}
		else cout<<"Repeated!\n";
	}
	else if(op=='L') {int w1=gethash(node[name]);
	    	int w2=gethash(key);
	    	if(w1==w2){
	    		if(node[name]==key) cout<<"Success!\n";
	    		else cout<<"Attention!\n";
			}
			else cout<<"Failed!\n";
	   
	}
	
}

return 0;

}
