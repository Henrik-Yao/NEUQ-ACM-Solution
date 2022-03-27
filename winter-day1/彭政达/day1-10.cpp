#include <bits/stdc++.h> 
using namespace std;
int main(){
    queue<int> q[100];
    int count=0,n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        bool flag=false;
        for(int j=0;j<count;j++){
            if(q[j].back()>x){
                q[j].push(x);
                flag=true;
                break;
            }
        }
        if(!flag){
            q[count].push(x);
            count++;
        }
    }
    for(int i=0;i<count;i++){
        if(q[i].back()==1){
            while(!q[i].empty()){
                cout<<q[i].front();
                q[i].pop();
                if(!q[i].empty()) cout<<' ';
                else cout<<endl;
            }
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}

