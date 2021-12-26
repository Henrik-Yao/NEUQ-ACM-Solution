#include<bits/stdc++.h>
using namespace std;
int l=0,r=0,flag=0;
stack<char>st;
int main(){
    string tex;
    while(cin>>tex){
    for(int i=0;i<tex.size();i++){
        if(tex[i]=='(')
        st.push('(');
        else if(tex[i]==')'){
        if(!st.empty()){
            st.pop();
        }
        else{
            r++;
        }
    }
    }
    while(!st.empty()){
        l++;
        st.pop();
    }
    if(l==0&&r==0)
    cout<<"Match";
    else{
        cout<<l+r<<endl;
    for(int i=1;i<=r;i++)
        cout<<'(';
    cout<<tex;
    for(int i=1;i<=l;i++)
        cout<<')';
    }
    cout<<endl;
    l=0;
    r=0;
    }
    
    return 0;
}