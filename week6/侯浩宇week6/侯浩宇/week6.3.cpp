#include<bits/stdc++.h>
using namespace std;
string b;
char a[819999];
int ans=0,p;
void sr(){
	scanf("%[^\n]",&a);	
    for(int i=0;a[i];i++)
	if(a[i]>='A'&&a[i]<='Z')
	a[i]+=32;//a
	cin>>b;
	for(int i=0;i<b.length();i++)
	if(b[i]>='A'&&b[i]<='Z')
	b[i]+=32;	//b		cout<<i<<" "<<i-j<<endl;
}
void ss(int j){
	for(int i=j;i<j+b.length();i++){
	if(a[i]!=b[i-j]){return;}		
	}
	p=1;
	return;
}
int main(){
	sr();
    for(int i=0;a[i];i++){
    	p=0;
    	while(a[i]>='a'&&a[i]<='z'){
    	if(!p)
		if(a[i]==b[0]){
		ss(i);	
		}
		i++;	
		}	if(p) ans++;
	}
	cout<<ans;
	return 0;
}
