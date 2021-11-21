#include<bits/stdc++.h>
using namespace std;
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)
struct Node{string c,zh,mm,hx;};
int n;
Node node[1005];
map<string,pair<string,string> > mp;
char preHash(string str){
	int sum=0;
	for(int i=0;i<str.length();i++){
		if(str[i]>='A'&&str[i]<='Z') str[i]=str[i]|32;
		if(str[i]>='0'&&str[i]<='9') sum+=str[i]-'0';
		else sum+=str[i]-'a'+10;
	}
	sum=sum%36;
	if(sum<10) return sum+'0';
	else return sum-10+'a';
}
string Hash(string str){
	string hx="0000";
	int l=str.length();
	int index[5]={0};
	for(int i=0;i<l%4;i++)
		index[i]++;
	int j=0;
	for(int i=0;i<4;i++){
		index[i]+=l/4;
		string str1=str.substr(j,index[i]);
		j+=index[i];
		char h=preHash(str1);
		hx[i]=h;
	}
	return hx;
}
int main(){
	ios::sync_with_stdio(false);
	filein;fileout;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>node[i].c>>node[i].zh>>node[i].mm;
		node[i].hx=Hash(node[i].mm);
		if(node[i].c=="R")
			if(mp.find(node[i].zh)!=mp.end())
				if(i==n-1) cout<<"Repeated!";
				else cout<<"Repeated!"<<endl;
			else{
				mp[node[i].zh].first=node[i].mm;
				mp[node[i].zh].second=node[i].hx;
				if(i==n-1) cout<<"Signed!";
				else cout<<"Signed!"<<endl;
			}
		else
			if(node[i].c=="L")
				if(mp.find(node[i].zh)==mp.end())
					if(i==n-1) cout<<"Failed!";
					else cout<<"Failed!"<<endl;
				else
					if(mp.find(node[i].zh)->second.first==node[i].mm)
						if(i==n-1) cout<<"Success!";
						else cout<<"Success!"<<endl;
					else
						if(mp.find(node[i].zh)->second.second==node[i].hx)
							if(i==n-1) cout<<"Attention!";
							else cout<<"Attention!"<<endl;
						else
							if(i==n-1) cout<<"Failed!";
							else cout<<"Failed!"<<endl;
	}		
	return 0;
}
