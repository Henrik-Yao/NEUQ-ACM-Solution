#include<bits/stdc++.h>
using namespace std;
void pr(string str,int num){
    int len=str.size();
	if(num==len-1)
		cout<<str<<endl;
	else
		for(int i=num;i<len;i++){
			swap(str[num],str[i]);
			pr(str,num+1);
		}
}
int main(){
	string s;
    ios::sync_with_stdio(false);
	cin>>s;
    //pr;
	sort(s.begin(),s.end());
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(),s.end()));
    
}
