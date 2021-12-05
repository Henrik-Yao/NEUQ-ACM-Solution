#include<bits/stdc++.h>
using namespace std;
map<char,int>a[1000];
int main(){
    string S;
    string T;
    int j=0;
   while(getline(cin,S)&&getline(cin,T)){
    int Tlength=T.length();
    int Slength=S.length();
    for(int i=0;i<Tlength;i++){a[j][T[i]]=1;
    }
    for(int i=0;i<Slength;i++){
        if(a[j][S[i]]!=1)cout<<S[i];
    }
       cout<<endl;
       j++;
   }
    return 0;
}
