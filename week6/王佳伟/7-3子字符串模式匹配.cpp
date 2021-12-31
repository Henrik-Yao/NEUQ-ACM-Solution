#include<bits/stdc++.h>
using namespace std;

int res = 0;

//��ʼ��ǰ׺��ע�����ڵ���Ҫ����ƶ�һλ�����Ե�n-1���ɣ� 
void prefix_table(string pattern, vector<int>& prefix, int n) {
	int len = 0;//��ƥ���ǰ׺������
	int i = 1;//iָģʽ����λ��  
	while(i < n) {
//		cout << i << len << endl;
		if(pattern[i] == pattern[len]){//ƥ������ 
			prefix[++i] = ++len;//����һ��λ����Ϊlen+1 
		}
		else{
			if(len != 0)
				len = prefix[len];
			else i++;
		}
	}
}

bool kmp(string text, string pattern){
	int m = text.size();
	int n = pattern.size();
	vector<int> prefix(n+1, 0);
	prefix_table(pattern, prefix, n);
//	for(int k = 0; k < n; k++){
//		cout << prefix[k] << " ";
//	}

	// text[i]      length = m  <--˵�� 
	// pattern[j]   length = n
	int i = 0, j = 0;
	while(i < m){
		//��� 
		if(text[i] == pattern[j]){
			if(j == n-1){//�ɹ�ƥ��������ģʽ�� 
//				cout << "found at" << i-j << endl; 
//			 	res++;//��¼���� 
			 	return true;
			 	j = prefix[j];//��j��֮ǰ�Ѿ�ƥ������ 
			 	continue;
			}
			i++; j++;//��δƥ��������ģʽ����go on! 
		}
		//���� 
		else{
			if(j == 0){//j�Ѿ����ʼ�� 
				i++;
			}
			else//˵����prefix[j] > 0 ���Լ��ٱ��� 
				j = prefix[j];
		}
	}
	return false;
}

int main() {
	string s, pattern;
	char c;
//	char ch[10000];
	while(c = getchar()){
		if(c == '\n') break;
		s.push_back(c);		
	}
//	cout << s << endl;
	cin >> pattern;
	int l = -1, r = -1;
//	int k = 'A' - 'a';
//	cout << k;
	for(int i = 0; i < pattern.size(); i++){
		if(pattern[i] >= 'a' && pattern[i] <= 'z') pattern[i] -= 32;//����ɴ�д  
	}
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;//����ɴ�д  
		if(s[i] >= 'A' && s[i] <= 'Z'){
			if(l == -1){
				l = i;
			}
			r = i;
		}
		else{
			if(l == -1) continue;
			else{
				string text = s.substr(l, r-l+1);
				l = r = -1; 
//				cout << "text = " << text << endl;
				if(kmp(text, pattern)){
					res++;
				}
			}
		}
	}
	if(l != -1){
			string text = s.substr(l, r-l+1);
//			cout << "text = " << text << endl;
			if(kmp(text, pattern)) res++;
		}
//	cout << s << endl;
//	cout << pattern << endl;
	cout << res;
//	for(int i = 0; i < s.size(); i++){
//		cout << s[i];
//	}
	 
}


