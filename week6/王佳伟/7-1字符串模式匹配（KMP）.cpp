#include<bits/stdc++.h>
using namespace std;

int res = 0;
//初始化前缀表（注：表内的数要向后移动一位，所以到n-1即可） 
void prefix_table(string pattern, vector<int>& prefix, int n) {
	int len = 0;//已匹配的前缀串长度
	int i = 1;//i指模式串的位置  
	while(i < n) {
//		cout << i << len << endl;
		if(pattern[i] == pattern[len]){//匹配上了 
			prefix[++i] = ++len;//将下一个位置设为len+1 
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

	// text[i]      length = m  <--说明 
	// pattern[j]   length = n
	int i = 0, j = 0;
	while(i < m){
		//相等 
		if(text[i] == pattern[j]){
			if(j == n-1){//成功匹配上整个模式串 
			 	res++;//记录个数 
			 	j = prefix[j];//第j个之前已经匹配上了 
			 	continue;
			}
			i++; j++;//还未匹配完整个模式串，go on! 
		}
		//不等 
		else{
			if(j == 0){//j已经到最开始了 
				i++;
			}
			else//说不定prefix[j] > 0 可以减少遍历 
				j = prefix[j];
		}
	}
}

int main() {
	string text;
//	string pattern = "ababc";//模式串
	string pattern;//模式串 000120123
	cin >> text >> pattern;
	kmp(text, pattern);
	cout << res << endl;
}


