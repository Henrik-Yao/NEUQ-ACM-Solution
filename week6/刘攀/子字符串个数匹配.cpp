#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<string.h>
string a,b;
int nextt[1000001];
int lena, lenb;
int sum[1000001];
int flag = 0;
int cou = 0;
int cou1 = 0;
void getnext(string b){
	int i = 0;
	int j = -1;
	nextt[0] = -1;
	while (i < b.size()) {
		if (j == -1 || b[i] == b[j]){
			i++;
			j++;
			nextt[i] = j;
		}
		else {
			j = nextt[j];
		}
	}
}
int kmp(string a, string b){
	int i = 0;
	int j = 0;
	while (i < a.size()){
		if ( i <= sum[cou]){
			if (j == -1 || a[i] == b[j]){
				i++;
				j++;
			}
			else {
				j = nextt[j];
			}
			if (j == b.size()){
				i = sum[cou];
				cou++;
				cou1++;
				j=nextt[j];
			}
		}
		else {
			i = sum[cou];
			cou++;
		}
	}
}
int main() {
	getline(cin,a);
	cin>>b;
	int lena=a.size();
	int lenb=b.size();
	for(int i=0;i<lena;i++)
	{
		if(a[i]>='A'&&a[i]<='Z') a[i]=a[i]+32;
		if(!(a[i]>='a'&&a[i]<='z')) a[i]=' ';				
	}
	for(int i=0;i<lenb;i++)
	{
		if(b[i]>='A'&&b[i]<='Z') b[i]=b[i]+32;	
	}
	for (int i = 0; i < lena; i++){
		if((a[i]>='a'&&a[i]<='z')&&(!(a[i+1]>='a'&&a[i+1]<='z'))){
			sum[flag]=i+1;
			flag++;
		}
	}
	getnext(b);
	kmp(a,b);
	cout << cou1;
}
