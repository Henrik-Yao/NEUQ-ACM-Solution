#include<bits/stdc++.h>
using namespace std;
int next[1000001]; 
string a,b;
long long sum=0;
int lena,lenb;
void getnext(string b){
	int i=0;
	int j=-1;
	next[0]=-1;
	while(i<b.size()){
		if(j==-1||b[i]==b[j]){
			i++;
			j++;
			next[i]=j;
		}
		else {
			j=next[j];
		}
	}
} 
int kmp(string a,string b){
	int i=0;
	int j=0;
	while(i<lena){
	if(j==-1||a[i]==b[j]){
		i++;
		j++;
	}
	else{
		j=next[j];
	}
	if(j==lenb){
		sum++;
		j=next[j];
	}
}
return sum;
}
int main(){
	cin>>a;
	cin>>b;
	lena=a.size();
	lenb=b.size();
	getnext(b);
	cout<<kmp(a,b)<<endl;
}





