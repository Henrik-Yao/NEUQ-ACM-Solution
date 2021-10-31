#include <bits/stdc++.h>
using namespace std;
void pl(string s){
	int len=s.size();
	int top,i;
	while(true){
		for(i=len-1;i>0;i--){
			if(s[i]>s[i-1]) {
                top=i;
                break;
            }
		}
		if(i==0) return;
		char minMax=s[top];
		int minMax_index;
		for(i=top;i<len;i++){
			if(s[i]>s[top-1]&&minMax>=s[i]) {
				minMax_index=i;
				minMax=s[i];
			}
		}
		swap(s[top-1],s[minMax_index]);
		for(i=top;i<(top+len)/2;i++){
			swap(s[i],s[len-i+top-1]);
		}
		cout<<s<<endl;
	}
} 
int main(){
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    cout<<str<<endl;
    pl(str);
    return 0;
}

