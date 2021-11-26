#include<bits/stdc++.h>
using namespace std;

unorder_map<string,string> sign;

int hash_(string s){
    int len = s.size();
    int num[105];
    for(int i=0; i<len; i++){
        if(s[i] >= '0' && s[i] <= '9')  num[i] = s[i] - '0';
        else if(s[i] >= 'a' && s[i] <= 'z')  num[i] = s[i] - 'a' +10;
        else if(s[i] >= 'A' && s[i] <= 'Z')  num[i] = s[i] - 'A' +10;
    }
    int mod = len % 4;
    int L[4];
    for(int i=0; i<4; i++){
        L[i] = len / 4;
        if(mod){
            L[i]++;
            mod--;
        }
        if(i)   L[i] += L[i-1];
    }
//    for(int i=0; i<4; i++){
//    	cout << L[i] << endl;
//	} 
    int t0 = 0,t1,t2,t3;
    t3 = t2 = t1 = t0;
    for(int i=0; i<L[0]; i++)
        t0 += num[i];
    for(int i=L[0]; i<L[1]; i++)
        t1 += num[i];
    for(int i=L[1]; i<L[2]; i++)
        t1 += num[i];
    for(int i=L[2]; i<L[3]; i++)
        t1 += num[i];
    t0 %= 36,t1 %= 36,t2 %= 36,t3 %= 36;
    return ((t0 * 36 + t1) * 36 +t2) * 36 +t3;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        char ch;
        string a,b;
        cin >> ch >> a >> b;
        if(ch == 'R'){
            if(sign.count(a) == 0){
                sign[a] = b;
                cout << "Signed!\n";
            }
            else{
                cout << "Repeated!\n";
            }
        }
        else{
            if(sign[a] == b){
                cout << "Success!\n";
            }
            else{
//            	cout << hash_(sign[a]) << endl << hash_(b) << endl;
                if(hash_(sign[a]) == hash_(b)){
                    cout << "Attention!\n";
                }
                else{
                    cout << "Failed!\n";
                }
            }
        }
    }
    return 0;
}

