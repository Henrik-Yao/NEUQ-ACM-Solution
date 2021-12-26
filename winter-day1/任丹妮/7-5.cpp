#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int l=0,r=0,i=0;
        while(s[i]!='\0'){
        if(s[i]=='(')
            l++;
        else if(s[i]==')'){
            if(l==0)
            {
                r++;
            }
            else {
                l--;
            }
        }
            i++;
    }
    if(l==0&&r==0){
        cout<<"Match"<<endl;
    }
    else {
        cout<<l+r<<endl;
        for(int i=0;i<r;i++)
        {
            cout<<"(";
        }
        cout<<s;
        for(int i=0;i<l;i++)
        {
            cout<<")";
        }
        cout<<endl;
    }
    }
        return 0;
}
