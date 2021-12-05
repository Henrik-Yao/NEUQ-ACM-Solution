#include <iostream>
#include <cstring>
using namespace std;
int hashing[257];
int main(){
	string strori,strdel;
	while(getline(cin,strori)){
	    getline(cin,strdel);
    	for(int i=0;i<257;i++) hashing[i]=0;
	    for(int i=0;i<strdel.size();i++){
    		hashing[(int)strdel[i]]=1;
    	}
    	for(int i=0;i<strori.size();i++){
    		if(hashing[(int)strori[i]]==0) cout << strori[i];
    	}
        cout << endl;
    }
	return 0;
}