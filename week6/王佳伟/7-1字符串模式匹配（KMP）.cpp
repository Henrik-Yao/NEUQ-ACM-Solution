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

void kmp(string text, string pattern){
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
			 	res++;//��¼���� 
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
}

int main() {
	string text;
//	string pattern = "ababc";//ģʽ��
	string pattern;//ģʽ�� 000120123
	cin >> text >> pattern;
	kmp(text, pattern);
	cout << res << endl;
}


