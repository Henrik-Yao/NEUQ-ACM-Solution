#include<bits/stdc++.h>
using namespace std;
void move(string a,string b){
    printf("%s->%s\n",a.c_str(),b.c_str());
}
void hanoi(int n,string a,string b,string c){
    if(n==1)
        move(a,c);
    else{
        hanoi(n-1,a,c,b);
        move(a,c);
        hanoi(n-1,b,a,c);
    }
}
int main(){
    string a,b,c;
    int n;
    cin>>n>>a>>b>>c;
    hanoi(n,a,b,c);
    return 0;
}
