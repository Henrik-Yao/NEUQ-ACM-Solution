#include<bits/stdc++.h>
using namespace std;
vector<char>Q;
int main(){
    string s;
    while(cin>>s){
        int length=s.length();
        int count=0;
        for(int i=0;i<length;i++){
            if(s[i]=='(')Q.push_back(s[i]);
            else if(s[i]==')'){
                if(Q.empty()){
                    count++;
                }
                else Q.erase(Q.begin());
            }
        }
       int left=Q.size();
        if(count==0&&left==0)cout<<"Match"<<endl;
        else {
            cout<<left+count<<endl;
            for(int i=0;i<count;i++)cout<<"(";
            cout<<s;
            for(int i=0;i<left;i++)cout<<")";
            cout<<endl;
        }
     Q.clear();
    }
    return 0;
}
