#include<iostream>
using namespace std; 

string solve(){	
    char c;	
    string s="",copy;	
    int t;			
    while(cin >> c){	
        if(c == '[')	{ 
            cin >> t;			
            copy = solve();			
            while(t--){
                s+=copy;
            } 		
        }		
        else if(c == ']') return s;		
            else s+=c;	
    } 
}
int main(){ 	
    cout << solve();
    return 0;
}
