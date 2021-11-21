#include<bits/stdc++.h>
using namespace std;
int n;
char opl;
string name,code;
map<string,string>acount;
////////////
pair<map<string,string>::iterator,bool> insert_pair;//判断map是否insert成功；
////////////
typedef unsigned long long ull;
map<string,ull>hashepp;
ull hashe(string code){
    int len[5];
    len[0]=code.size();
    int temp,rmd;
    temp=len[0]/4;
    rmd=len[0]%4;
    len[0]=0;
    for(int i=1;i<=4;i++){
        if(i<=rmd)
        len[i]=len[i-1]+temp+1;
        else if(i>rmd)
        len[i]=len[i-1]+temp;
        else;
    }//以上为分割
    ull ans[5]={0};
    for(int i=0;i<len[1];i++){
        if(code[i]>='A'&&code[i]<='Z')
        ans[1]=(ans[1]+(ull)(code[i]-('A'-10)))%36;
        else if(code[i]>='a'&&code[i]<='z')
        ans[1]=(ans[1]+(ull)(code[i]-('a'-10)))%36;
        else if(code[i]>='0'&&code[i]<='9')
        ans[1]=(ans[1]+(ull)(code[i]-('1'-1)))%36;
        else;
    }
    for(int i=len[1];i<len[2];i++){
        if(code[i]>='A'&&code[i]<='Z')
        ans[2]=(ans[2]+(ull)(code[i]-('A'-10)))%36;
        else if(code[i]>='a'&&code[i]<='z')
        ans[2]=(ans[2]+(ull)(code[i]-('a'-10)))%36;
        else if(code[i]>='0'&&code[i]<='9')
        ans[2]=(ans[2]+(ull)(code[i]-('1'-1)))%36;
        else;
    }
    for(int i=len[2];i<len[3];i++){
       if(code[i]>='A'&&code[i]<='Z')
        ans[3]=(ans[3]+(ull)(code[i]-('A'-10)))%36;
        else if(code[i]>='a'&&code[i]<='z')
        ans[3]=(ans[3]+(ull)(code[i]-('a'-10)))%36;
        else if(code[i]>='0'&&code[i]<='9')
        ans[3]=(ans[3]+(ull)(code[i]-('1'-1)))%36;
        else;
    }
    for(int i=len[3];i<len[4];i++){
        if(code[i]>='A'&&code[i]<='Z')
        ans[4]=(ans[4]+(ull)(code[i]-('A'-10)))%36;
        else if(code[i]>='a'&&code[i]<='z')
        ans[4]=(ans[4]+(ull)(code[i]-('a'-10)))%36;
        else if(code[i]>='0'&&code[i]<='9')
        ans[4]=(ans[4]+(ull)(code[i]-('1'-1)))%36;
        else;
    }
    ans[0]=((ans[1]%36*36+ans[2]%36)*36+ans[3]%36)*36+ans[4];
    return ans[0];
}//此处哈希的值为36进制转换为10进制的值；
int main(){
  cin>>n;
  while(n--){
     cin>>opl;
     if(opl=='R'){
         cin>>name>>code;
         insert_pair = acount.insert(pair<string,string>(name,code));
         if(insert_pair.second==true){
             cout<<"Signed!";
             hashepp[code]=hashe(code);
         }
         else{
             cout<<"Repeated!";
         }
     }
    else{
        cin>>name>>code;
        if(acount[name]==code){
            cout<<"Success!";
        }
        else{
            if(hashepp[acount[name]]==hashe(code)){
                cout<<"Attention!";
            }
            else
            cout<<"Failed!";
        }
    }
    if(n>=1) cout<<"\n";
  }


    return 0;
}