#include<bits/stdc++.h>
using namespace std;
int N;
char c;
string name,pass;
map<string,string> MAP;

int summ(string pass,int left,int right){   //求某一分块的哈希值 
	int sum=0;
	for(int i=left;i<=right;i++){
		if(pass[i]>='A'&&pass[i]<='Z') sum+=int(pass[i]-'A')+10;
		else if(pass[i]>='a'&&pass[i]<='z') sum+=int(pass[i]-'a')+10;
		else sum+=int(pass[i])-48;
	}
	return sum%36;
}

int haxi(string pass){             //求总体的哈希值 
	int len=pass.length();
	int l[5],i=0;
	for(int i=1;i<=4;i++){
		l[i]=len/4;
	}
	len-=l[1]*4;
	while(len){
		i++;
		l[i]++;
		len--;
	}
	int s1=summ(pass,0,l[1]-1);
	int s2=summ(pass,l[1],l[1]+l[2]-1);
	int s3=summ(pass,l[1]+l[2],l[1]+l[2]+l[3]-1);
	int s4=summ(pass,l[1]+l[2]+l[3],l[1]+l[2]+l[3]+l[4]-1);
	return s1*36*36*36+s2*36*36+s3*36+s4; 
}
int main() {
	cin>>N;
	while(N--){
		string name,pass;
		cin>>c>>name>>pass;
		if(c=='L'){
			if(MAP.count(name)){  //如果用户名存在 
				if(pass!=MAP[name]){    //如果密码不正确 
				int haxi1=haxi(pass);
				int haxi2=haxi(MAP[name]);
				if(haxi1==haxi2) cout<<"Attention!";
				else cout<<"Failed!";
				}
				else cout<<"Success!";
			}
			else cout<<"Failed!";
		}
		else if(c=='R'){
			if(MAP.count(name)) cout<<"Repeated!";
			else{
				MAP.insert(std::pair<string,string>(name,pass));
				cout<<"Signed!";
			}
		}
		if(N) cout<<endl;
	}
	return 0;
}


