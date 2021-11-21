#include <bits/stdc++.h>
using namespace std;
int num=0;
void prefix_table(string pattern,int prefix[],int n){
	prefix[0]=0;
	int len=0,i=1;
	while(i<n){
		if(pattern[i]==pattern[len]){
			len++;
			prefix[i]=len;
			i++;
		}
		else if(len>0) len=prefix[len-1];
		else{
			prefix[i]=len;
			i++;
		}
	}
} 
void move_prefix_table(int prefix[],int n){
	for(int i=n-1;i>0;i--)
		prefix[i]=prefix[i-1];
	prefix[0]=-1;
}
void kmp_search(string pattern,string text){
	int n=pattern.size();
	int m=text.size();
	int * prefix=(int*)malloc(sizeof(int) * n);
	prefix_table(pattern,prefix,n);
	move_prefix_table(prefix,n);
	int i=0,j=0;
	while(i<m){
		if(j==n-1 && text[i]==pattern[j]){
			num++;
			j=prefix[j];
		}
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			j=prefix[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
}
int main(){
	string pattern,text;
	cin>>text>>pattern;
	kmp_search(pattern,text);
	cout<<num;
	return 0;
}
