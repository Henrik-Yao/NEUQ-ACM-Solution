#include <bits/stdc++.h>
using namespace std;
map<char,int>visit;
int main(){
    string a="",b="";
    while(getline(cin,a),getline(cin,b)){
    int len=b.length();
    for(int i=0;i<len;i++)
        {
            visit[b[i]]=1;
        }
    int len1=a.length();
    for(int i=0;i<len1;i++){
        if(visit[a[i]]==0)
            {
                cout<<a[i];
            }
    }
    for(int i=0;i<len;i++)
        {
            visit[b[i]]=0;
        }
        cout<<endl;
    }
    return 0;
}

