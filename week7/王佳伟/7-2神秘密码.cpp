#include<bits/stdc++.h>
using namespace std;

string s;
int len;
int k = 0;

string dispress(){
	string ans = "";
	string res = "";
	int num = 0;
	while(s[k] != ']'){
		if(s[k] >= '1' && s[k] <= '9'){
			if(s[k+1] >= '0' && s[k+1] <= '9'){
				num = 10 * (s[k]-'0') + (s[k+1]-'0');
				k++;
			}
			else {
				num = s[k]-'0';
			}
		}
		else if(s[k] == '['){
			k++;
			string tmp = dispress();
			res += tmp;
		}
		else res += s[k];
		k++;
	}
	while(num--){
		ans += res;
	}
	return ans;
}

int main() {
	cin >> s;
	len = s.size();
	int num1 = 0;
	while(k < len) {
		if(s[k] == '['){
			num1++;
			k++;
			string s = dispress();
			cout << s;
		}
		else if(s[k] == ']'){
			num1--;
			k++;
		}
		else if(num1 == 0){
			cout << s[k++];
		}
	}
}
