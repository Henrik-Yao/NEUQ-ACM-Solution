#include <bits/stdc++.h>
using namespace std;
void move(string x,string y){
    printf("%s->%s\n",x.c_str(),y.c_str());
}
void hanoi(int x,string a,string b,string c){
    if(x==1)    move(a,c);
    else{
        hanoi(x-1,a,c,b);
        move(a,c);
        hanoi(x-1,b,a,c);
    }
}
int main(){
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;
    hanoi(n,a,b,c);
    return 0;
}
