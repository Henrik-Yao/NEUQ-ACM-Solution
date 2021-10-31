#include <bits/stdc++.h>
using namespace std;
void trans(string from,string inter,string to,int level){
    if(level==1) {
        cout<<from<<"->"<<to<<endl;
        return;
    }
    else {
        trans(from,to,inter,level-1);
        cout<<from<<"->"<<to<<endl;
        trans(inter,from,to,level-1);
    }
}
int main(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    trans(a,b,c,n);
    return 0;
}
