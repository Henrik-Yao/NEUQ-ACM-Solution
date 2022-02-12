#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,len=0;
    int min=0,max=0,d;
    string str;
    getline(cin,str);
    for(i=0;str[i]!='#';i++) len++;
    for(i=0;i<len;i++){
    	if(str[i]=='(') min=i;
    	else if(str[i]==')') max=i;
    }
    for(i=0;i<len;i++){
        if(str[i]=='A') cout<<"sae";
        else if(str[i]=='B') cout<<"tsaedsae";
        else
		if(str[i]=='('){
        	cout<<str[i+1];
           	for(d=max-1;d>min+1;d--) cout<<str[d]<<str[i+1];
        	i=max;
        }
    }
    cout<<endl;
    return 0;
}
