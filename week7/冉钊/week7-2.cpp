#include<bits/stdc++.h>
using namespace std;
string transl(){
    int num;
    int tch;
    string temp,trans;
    while((tch=getchar())!=-1){
            char ch=tch;
            if(ch=='['){
                cin>>num;
               temp=transl();
               while(num--) trans+=temp;
            } 
            else if(ch==']'||ch=='\n'||ch==' ')
                return trans;
            
            else
            trans+=ch;
            
    }
}

int main(){
    cout<<transl();
    return 0;
}