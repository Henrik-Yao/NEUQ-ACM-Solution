#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
typedef long long ll;
int nextp[1000001];
int KMP(string str1,string str2){
	int i=0;
	int j=0;
	int len1=str1.length();
	int len2=str2.length();
	int cnt=0;
	while (i<len1&&j<len2){   
		if (j==-1||str1[i]==str2[j]){
			i++;
			j++;
		}
		else{   
			j=nextp[j];
		}		
		if (j==len2) {
			cnt++;
			j=nextp[j-1];
			i--;
		}
	}
	return cnt;	
}
void calcnext(string str){
	int len=str.length();
	nextp[0]=-1;
	int k=-1;
	int j=0;
	while (j<len-1){
		if (k==-1||str[k]==str[j]){
			k++;
			j++;
			nextp[j]=k;
		}
		else k=nextp[k];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string str1,str2;
	cin>>str1>>str2;
	calcnext(str2);
	cout<<KMP(str1,str2)<<endl;
	return 0;
} 
