#include<bits/stdc++.h>
using namespace std;
struct Node{
	string c; 
	string zh; 
	string mm; 
	string hx; 
};
int n;
Node node[1005];
map<string,pair<string,string> > mp;
char hash1(string str){
	int sum=0;
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z') 
		str[i]=str[i]|32;
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
string hash2(string str){
	string hx="0000";
	int l=str.length();
	int index[5]={0};
	for(int i=0;i<l%4;i++){
		index[i]++;
	}
	int j=0;
	for(int i=0;i<4;i++){
		index[i]+=l/4;
		string str1=str.substr(j,index[i]);
	
		j+=index[i];
		char h=hash1(str1);
		hx[i]=h;
	}
	return hx;
}
int main(void){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>node[i].c>>node[i].zh>>node[i].mm;
		node[i].hx=hash2(node[i].mm);

		if(node[i].c=="R"){
			if(mp.find(node[i].zh)!=mp.end()){
				cout<<"Repeated!";if(i<n-1)cout<<endl;}
			else {
				mp[node[i].zh].first=node[i].mm;
				mp[node[i].zh].second=node[i].hx;
				cout<<"Signed!";if(i<n-1)cout<<endl;
			}
		}else if(node[i].c=="L"){
			if(mp.find(node[i].zh)==mp.end()){
				cout<<"Failed!";if(i<n-1)cout<<endl;
			}
			else{
				if(mp.find(node[i].zh)->second.first==node[i].mm) 
				{cout<<"Success!";if(i<n-1)cout<<endl;}
				else{

					if(mp.find(node[i].zh)->second.second==node[i].hx)
					{cout<<"Attention!";if(i<n-1)cout<<endl;}
					else {cout<<"Failed!";if(i<n-1)cout<<endl;}
				}
			}
		}
	}		
	return 0;
}
