#include<iostream>
#include<string>
using namespace std;
void dfs(int n,string from,string temp,string to){
    if(n==1) cout<<from<<"->"<<to<<endl;
    else{
        dfs(n-1,from,to,temp);
        cout<<from<<"->"<<to<<endl;
        dfs(n-1,temp,from,to);
        
    }
    
    
}
int main(){
    int n;
    string from,temp,to;
    cin>>n>>from>>temp>>to;
    dfs(n,from,temp,to);
    
    
    return 0;
}