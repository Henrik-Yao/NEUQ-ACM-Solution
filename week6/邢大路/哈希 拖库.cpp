#include<bits/stdc++.h>
using namespace std;
map<string,int>M;
char small_hash(string str){
	int sum=0;
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]+32;
		if(str[i]>='0'&&str[i]<='9'){
			sum+=str[i]-'0';
		}else{
			sum+=str[i]-'a'+10;
		}
	}

	sum=sum%36;
	
	if(sum<10) return sum+'0';
	else return sum-10+'a';
}
string Hash(string code){
	string hx="0000";
	int length=code.length();
	int num[5]={0};
	for(int i=0;i<length%4;i++)num[i]++;
	for(int i=0;i<4;i++)num[i]+=length/4;
	int j=0;
	for(int i=0;i<4;i++){
		string str=code.substr(j,num[i]);
		j+=num[i];
		hx[i]=small_hash(str);
	}
	return hx;
}
struct P{
    char state;
    string name;
    string code;
    string hash;
};
int main(){
    int n;
    cin>>n;
    struct P a[n];
    struct P b[n];
 for(int i=0;i<n;i++){
     cin>>a[i].state;
     cin>>a[i].name>>a[i].code;
     	a[i].hash=Hash(a[i].code);
     }
     for(int i=0;i<n;i++){
         if(a[i].state=='R'){//如果是注册操作
             if(M[a[i].name]){
                 cout<<"Repeated！"<<endl;
             }//注册过
         else if(!M[a[i].name]){
         	
             b[i].name=a[i].name;
             b[i].code=a[i].code;
             
             b[i].hash=a[i].hash;
             cout<<"Signed!"<<endl;
             M[a[i].name]=1;
         }//没注册过
         }
         else if(a[i].state=='L'){//如果是登录操作
             if(M[a[i].name]!=1){
                 cout<<"Failed!"<<endl;
             }   //没注册过
             
        //注册过 
        else
		{
		int k;
		for(k=0;k<n;k++){
			if(b[k].name==a[i].name)break;
		}//找到这个名字的信息在哪里 
	
		if(a[i].hash==b[k].hash&&a[i].code==b[k].code)cout<<"Success!"<<endl;
		else if(a[i].hash==b[k].hash&&a[i].code!=b[k].code) cout<<"Attention!"<<endl;//密码错误
		else if(a[i].hash!=b[k].hash)cout<<"Failed!"<<endl;
	    
   }
     }
	 }
	 return 0;
}
