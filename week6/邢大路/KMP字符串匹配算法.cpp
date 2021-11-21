#include<bits/stdc++.h>
using namespace std;
int main(){
    string S,T;
    int count=0;
    cin>>S>>T;
    int Slength=S.length();
    int Tlength=T.length();
    int next[Tlength];
    next[0]=-1;
    int i=0;
    int j=-1;
    while(i<Tlength-1){
        if(j==-1||T[i]==T[j]){
        ++j;
        ++i;
        next[i]=j;
    }
        else j=next[j];
    }
     i=0;
     j=0;
    while(i<Slength&&j<Tlength){
        if(j==-1||S[i]==T[j]){
            ++i;
            ++j;
        }
        else j=next[j];
        if(j==Tlength){
            count++;
            i--;
            j=next[j-1];
    }
    }
    cout<<count<<endl;
    return 0;
}
