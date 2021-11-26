#include<bits/stdc++.h>
using namespace std;
int main(){
    string S,T;
    getline(cin,S);
	getline(cin,T);
    int Slength=S.length();
	int Tlength=T.length();
    for(int i=0;i<Slength;i++){
       if(S[i]>='A'&&S[i]<='Z')S[i]=S[i]+32;
       else if(S[i]>='a'&&S[i]<='z')continue;
        else S[i]=' ';
    }
    for(int i=0;i<Tlength;i++){
        if(T[i]>='A'&&T[i]<='Z')T[i]=T[i]+32;
    }
    int ans=0;
    for(int i=0;i<Slength;i++){
        if(Slength-i<Tlength)break;
        int m=S.find(T,i);
        if(m==-1)break;
        ans++;
       while(S[m]>='a'&&S[m]<='z')m++;
        i=m;
    }
    cout<<ans;
    return 0;
}
