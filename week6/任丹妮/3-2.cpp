#include <bits/stdc++.h>
using namespace std;
map<string,int>sign;
map<string,string>U;
struct {
    string name;
    string code;
}user;
string Haxi(string t){
    int len=t.length();
    int a[5];
    int i=4,j=1;
    a[0]=0;
    if(len%4!=0){
        while(i){
        if(i*(len/i)!=len) a[j]=len/i+1;
        else a[j]=len/i;
        len-=a[j];
        j++;
        i--;
    }
    }
    else {
        for(int i=1;i<5;i++){
        a[i]=len/4;
    }
    }
    string s[4];
    string total;
    int count=0;
    for(int k=0;k<4;k++)
    {
        count+=a[k];
        s[k]=t.substr(count,a[k+1]);
        int sum=0;
        for(j=0;j<s[k].length();j++){
            if(s[k][j]>='A'&&s[k][j]<='Z')
                sum+=s[k][j]-'A'+10;
            else if(s[k][j]>='a'&&s[k][j]<='z')
                sum+=s[k][j]-'a'+10;
            else sum+=s[k][j]-'0';
        }
        if(sum%36<=9&&sum%36>=0) total+=sum%36+48;
        else total+=(sum%36-10)+'a';
    }
    return total;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        cin>>user.name>>user.code;
        if(c=='R'&&sign[user.name]==0)
            {
                sign[user.name]=1;
                U[user.name]=user.code;
                cout<<"Signed!";
            }
        else if(c=='R'&&sign[user.name]==1)
        cout<<"Repeated!";
        else if(c=='L'&&(sign[user.name]==0)||((U[user.name]!=user.code)&&Haxi(U[user.name])!=Haxi(user.code)))
        cout<<"Failed!";
        else if(c=='L'&&sign[user.name]==1&&U[user.name]!=user.code&&Haxi(U[user.name])==Haxi(user.code))
        cout<<"Attention!";
        else if(c=='L'&&sign[user.name]==1&&U[user.name]==user.code)
        cout<<"Success!";
        if(n) cout<<endl;
    }
    return 0;
}
