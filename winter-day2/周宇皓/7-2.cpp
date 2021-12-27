#include<bits/stdc++.h>
using namespace std;
vector<char> post,in;
bool check(string str1,string str2) { 
    if(!str1.length()&&!str2.length()) return true; //两个都为0
    if(str1.length()!=str2.length()) return false;
    char root = str1[str1.length()-1]; //后
    int k;
    for(k=0;k<str2.length();k++) {
        if (root==str2[k])
            break;
    }
    string str1l = str1.substr(0,k);
    string str1r = str1.substr(k, str1.length() - 1 - k);
    string str2l = str2.substr(0,k);
    string str2r = str2.substr(k+1);
    for (int i=0;i<str1l.length();i++) {
        if (str2l.find(str1l[i])==str2l.npos) return false;
    }
    for (int i=0;i<str1r.length();i++) {
        if (str2r.find(str1r[i])==str2r.npos) return false;
    }
    return check(str1l,str2l)&&check(str1r,str2r);
}
void pre(int root,int start,int end){
	if(start>end) return;
	int k;
	for(k=start;k<end;k++)
		if(in[k]==post[root]) break;
	cout << post[root];	
	pre(root-1-end+k,start,k-1);
	pre(root-1,k+1,end);
}
int GetHeight(int root,int start,int end){
	if(start<=end){
		int k;
		for(k=start;k<end;k++){
			if(in[k]==post[root]) break;
		}
		int hl = GetHeight(root-1-end+k,start,k-1);  
		int hr = GetHeight(root-1,k+1,end);  
        return max(hl,hr)+1;  
	}else return -1;  //这题貌似认为空树深度为-1...
}
int main(){
	string str1="",str2="";
	while(cin>>str1>>str2)
    {
        post.clear(),in.clear();
        	for(int i=0;i<str1.size();i++){
		if(str1[i]>='A'&&str1[i]<='Z') post.push_back(str1[i]);
	} 
	for(int i=0;i<str2.size();i++){
		if(str2[i]>='A'&&str2[i]<='Z') in.push_back(str2[i]);
	} 
	if(check(str1,str2)){
        int N = post.size();
		cout << GetHeight(N-1,0,N-1) << endl;
		pre(N-1,0,N-1);
        cout<<endl;
	}else cout << "INVALID"<<endl;
    }
	return 0;
}
