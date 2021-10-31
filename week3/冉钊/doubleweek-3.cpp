#include<iostream>
using namespace std;
long long dfs(int n){
   if(n==1) return 2;
   else{
       return 3*dfs(n-1)+2;
   }
}
int main(){
     int n;
     while(cin>>n){
        cout<<dfs(n)<<endl;
     }
    return 0;
}