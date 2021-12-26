#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int>Q;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)Q.push_back(i);
    int flag=1;
    int M;
    while(Q.size()>=1){
    	  M=Q.front();
            Q.erase(Q.begin());
            reverse(Q.begin(),Q.end());
            Q.insert(Q.begin(),M);
        if(flag){
         for(int i=0;i<m;i++){
                M=Q.front();
                Q.erase(Q.begin());
                if(i!=m-1)Q.push_back(M);
                else cout<<M<<" ";
            }
            flag=0;
        }
        else{
             for(int i=0;i<k;i++){
                M=Q.front();
                Q.erase(Q.begin());
                if(i!=k-1)Q.push_back(M);
                else cout<<M<<" ";
        }
            flag=1;
    }
}
        return 0;
}
