### **7-1 字符串模式匹配（KMP）**

用next数组预处理字符串。

```c++
#include<bits/stdc++.h>
using namespace std;
char s[1000005],p[1000005];
int Next[1000005];
void GetNext(int p1){
	int k=-1;
	Next[0]=-1;
	int j=0;
	while(j<p1){
		if(k==-1||p[j]==p[k]){
			j++;
			k++;
			Next[j]=k;
		}else {
			k=Next[k];
		}
	}
}
int KMP(int s1,int p1){
	int i=0;
	int j=0;
	int cnt=0;
	while(i<s1&&j<p1){
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
		}else{
			j=Next[j];
		}
		if(j==p1)cnt++,j=Next[j-1],i--;
	}
	return cnt; 
}
int main(){
	int s1,p1;
	for(s1=0;(s[s1]=getchar())!='\n';s1++);
	for(p1=0;(p[p1]=getchar())!='\n';p1++);
	GetNext(p1);
	cout<<KMP(s1,p1);
}
```

### **7-2 妈妈再也不用担心我被拖库啦！**

计算密码的hash值，比对成功后再比对密码本身。

```c++
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
				cout<<"Repeated!";
				if(i<n-1)cout<<endl;
			}
			else{
				mp[node[i].zh].first=node[i].mm;
				mp[node[i].zh].second=node[i].hx;
				cout<<"Signed!";
				if(i<n-1)cout<<endl;
			}
		}else 
		 if(node[i].c=="L"){
			if(mp.find(node[i].zh)==mp.end()){
				cout<<"Failed!";
				if(i<n-1)cout<<endl;
			}
			else{
if(mp.find(node[i].zh)->second.first==node[i].mm) {
					cout<<"Success!";
					if(i<n-1)cout<<endl;}
				else{
if(mp.find(node[i].zh)->second.second==node[i].hx){
						cout<<"Attention!";
						if(i<n-1)cout<<endl;
					}
					else{
						cout<<"Failed!";
						if(i<n-1)cout<<endl;
					}
				}
			}
		}
	}		
	return 0;
}
```

### **7-3 子字符串个数匹配**

遍历字母中与b串首字符相同的串，成功后记录，直到非字母字符再次计算。

```c++
#include<bits/stdc++.h>
using namespace std;
string b;
char a[819999];
int ans=0,p;
void sr(){
	scanf("%[^\n]",&a);	
    for(int i=0;a[i];i++)
	if(a[i]>='A'&&a[i]<='Z')
	a[i]+=32;//a
	cin>>b;
	for(int i=0;i<b.length();i++)
	if(b[i]>='A'&&b[i]<='Z')
	b[i]+=32;	//b		cout<<i<<" "<<i-j<<endl;
}
void ss(int j){
	for(int i=j;i<j+b.length();i++){
	if(a[i]!=b[i-j]){return;}		
	}
	p=1;
	return;
}
int main(){
	sr();
    for(int i=0;a[i];i++){
    	p=0;
    	while(a[i]>='a'&&a[i]<='z'){
    	if(!p)
		if(a[i]==b[0]){
		ss(i);	
		}
		i++;	
		}	if(p) ans++;
	}
	cout<<ans;
	return 0;
}
```

