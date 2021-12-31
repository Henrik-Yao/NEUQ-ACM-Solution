#include<bits/stdc++.h>
using namespace std;
vector<string> str(10086,"");

int main(){
    string s,S;
    getline(cin,S);
    cin >> s;
    int len_s = s.size(),len_S = S.size();
    int m = 1;
    int flag = 0;
    for(int i=0; i<len_S; i++){
        if(S[i] >= 'a' && S[i] <= 'z'){
            S[i] = S[i] -('a' - 'A');
        }
        if(S[i] < 'A' || S[i] > 'Z'){
            if(flag){
                flag = 0;
                m++;
            }
            continue;
        }
        else{
            if(!flag)   flag = 1;
            str[m] += S[i];
        }
    }
//    for(int i=1; i<=m; i++){
//    	printf("%s\n",str[i].c_str());
//	} 
	for(int i=0; i<len_s; i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i] -('a' - 'A');
        }
	} 
    int cnt = 0;
    for(int i=1; i<=m; i++){
        if(str[i].find(s) != string::npos){
            cnt++;
        }
    }
    cout << cnt;
}
