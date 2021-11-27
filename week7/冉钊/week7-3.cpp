#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
bool vst[100010]={0};
string tex,pat;
ull flag=0;
int main(){
    while(getline(cin,tex)){
        //if(flag!=0) cout<<"\n";
        memset(vst,0,100010);
        getline(cin,pat);
        for(ull i=0;i<pat.size();i++){
            vst[(int)pat[i]]=1;
        }
        for(ull j=0;j<tex.size();j++){
            if(!vst[(int)tex[j]]) cout<<tex[j];
        }
        cout<<endl;
        //flag++;
    }
    return 0;
}