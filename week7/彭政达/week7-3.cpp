#include <bits/stdc++.h>
using namespace std;
int sign[1010];
int main(){
	string str1,str2;
	while(cin>>str1)){
	    cin>>str2;
    	memset(hash,0,sizeof(hash));
	    for(int i=0;i<str2.size();i++)
    		sign[(int)str2[i]]=1;
    	for(int i=0;i<str1.size();i++)
    		if(!sign[(int)str1[i]])
				cout<<str1[i];
        cout<<endl;
    }
}
