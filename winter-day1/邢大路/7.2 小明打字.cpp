#include<bits/stdc++.h>
using namespace std;
vector<char>S;
char a;
int main(){
    string s;
    int index=0;
    getline(cin,s);
    int length=s.length();
    int flag=0;
    for(int i=0;i<length;i++){

        if(s[i]=='[')index=0;
        else if(s[i]==']')index=S.size();
        else if(s[i]=='{'){
        	if(index-1>=0)index--;
		}
		else if(s[i]=='}'){
			if(index+1<=S.size())index++;
		}
		else if(s[i]=='-'){
			flag++;
		}
		else if(s[i]=='='){
		   if(!S.empty()){
               S.erase(S.begin()+index-1);
               index--;
           }
	}
		else {
			if(flag%2==0){
			 if(index==S.size()-1){
                 S.push_back(s[i]);
              }
                else S.insert(S.begin()+index,s[i]);
                index++;
            }
			else {
				S[index]=s[i];
                index++;
			}
		}
    }
    for(int i=0;i<S.size();i++)cout<<S[i];
    cout<<endl;
    return 0;
    
}
    
