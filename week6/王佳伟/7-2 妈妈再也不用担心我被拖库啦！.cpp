#include<bits/stdc++.h>
using namespace std;

//���֧��36���� 
char z[36]={'0','1','2','3','4','5','6','7','8','9',
'a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z'}; 


string calculate(string s){//����s�Ĺ�ϣֵ 
	string ss = "";
	int n = s.size();
	int len[4] = {0};
	for(int i = 4; i >= 1 ; i--){
		if(n % i > 0){
			len[4-i] = n / i + 1;
		}
		else len[4-i] = n / i;
		n -= len[4-i];
	}
	//��ÿһ�ε�ÿһλת��Ϊ10�������
	int index = 0;
	for(int i = 0; i < 4; i++){
		string str = s.substr(index, len[i]);
		index += len[i];
		int res = 0;
		for(int j = 0; j < str.size(); j++) {
			if(str[j] >= 'a' && str[j] <= 'z')//��֤�ɴ�д��ĸ�������� 
				str[j] -= 32;
			if(str[j] >= 'A' && str[j] <= 'Z'){
				res += str[j] - 'A' + 10;
			}
			else{
				res += str[j] - '0';
			}
		}
//		cout << str << " ";
//		cout << res << " ";
		res %= 36;
		ss.push_back(z[res]);
	} 
	return ss;
}

typedef pair<string, string> pir;
unordered_map<string, pir> mp;

int main() {
	string s1, s2, s;
	char c;
	int n;
	cin >> n;
	while(n--){
		cin >> c >> s1 >> s2;
		if(c == 'L'){//��¼��1�û�����2���룬3��ϣ��� 
			s = calculate(s2);
			if(!mp.count(s1)){
				cout << "Failed!" ;
			}
			else if(s2 == mp[s1].first){
				cout << "Success!" ;
			}
			else if(s == mp[s1].second){
				cout << "Attention!";
			}
			else{
				cout << "Failed!" ;
			}
		}
		else if(c == 'R'){//ע��
			if(!mp.count(s1)) {
				mp[s1].first = s2;
				mp[s1].second = calculate(s2);
				cout << "Signed!" ;
//				continue;
			}
			else cout << "Repeated!" ;
		}
		if(n != 0) cout << endl;
	}
	 
}
/*
6
R IronMan 1234qwerasdf
R IronMan whejrdfs345
L IronMan 1234qwerasdf
L IronMan whejrdfs345
L IronMan 0km6trlhdcwc
L Tom 649913332
*/

