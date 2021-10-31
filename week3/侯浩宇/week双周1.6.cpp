#include<bits/stdc++.h>//È«ÅÅÁÐstl 
using namespace std;
int main(){
	char s[10];
	int p=1;
	cin>>s;
	while(p){
		p=0;
	    for(int i=1;i<strlen(s);i++){
		    if(s[i-1]>s[i]) swap(s[i-1],s[i]),p=1;	
	    }	
	}
	
		printf("%s\n",s);
		while(next_permutation(s,s+strlen(s)))
			printf("%s\n",s);
		printf("\n");
	
	return 0;
}	
