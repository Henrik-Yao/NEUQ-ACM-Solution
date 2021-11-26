## Week 6 字符串题解

#### **7-1 字符串模式匹配（KMP）**

**核心思想**就是用一个数组prefix[i]保存模式串从0到i，头尾重合的最长距离。这样当匹配失败不需要从模式串的开头比较，只需要从prefix[i]开始比即可。

```C++
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


```



#### **7-2 妈妈再也不用担心我被拖库啦！**

分析：计算哈希值并将用户名，用户密码，哈希值对应即可。

对应：使用哈希表unordered_map<string,    > 将字符串映射到结构体，pair，都行

计算哈希值：先将每一位转换为10进制，相加，再转化为36进制，合并即可

```C++
#include<bits/stdc++.h>
using namespace std;

//最高支持36进制 
char z[36]={'0','1','2','3','4','5','6','7','8','9',
'a','b','c','d','e','f','g','h','i','j','k','l','m',
'n','o','p','q','r','s','t','u','v','w','x','y','z'}; 


string calculate(string s){//返回s的哈希值 
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
	//将每一段的每一位转换为10进制相加
	int index = 0;
	for(int i = 0; i < 4; i++){
		string str = s.substr(index, len[i]);
		index += len[i];
		int res = 0;
		for(int j = 0; j < str.size(); j++) {
			if(str[j] >= 'a' && str[j] <= 'z')//保证由大写字母代表数字 
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
		if(c == 'L'){//登录，1用户名，2密码，3哈希检测 
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
		else if(c == 'R'){//注册
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
```



#### **7-3 子字符串个数匹配**

分析：将字符串分割成符合要求的子字符串，对每个字符串利用kmp查找是否出现模式串。

分割：利用两个变量l和r分别指向符合要求的两端当s[r]对应的字符不满足要求，就通过substr(l, r-l+1)分割出一个字符串

```C++
#include<bits/stdc++.h>
using namespace std;

int res = 0;

//初始化前缀表（注：表内的数要向后移动一位，所以到n-1即可） 
void prefix_table(string pattern, vector<int>& prefix, int n) {
	int len = 0;//已匹配的前缀串长度
	int i = 1;//i指模式串的位置  
	while(i < n) {
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

bool kmp(string text, string pattern){
	int m = text.size();
	int n = pattern.size();
	vector<int> prefix(n+1, 0);
	prefix_table(pattern, prefix, n);

	// text[i]      length = m  <--说明 
	// pattern[j]   length = n
	int i = 0, j = 0;
	while(i < m){
		//相等 
		if(text[i] == pattern[j]){
			if(j == n-1){//成功匹配上整个模式串 
			 	return true;
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
	return false;
}

int main() {
	string s, pattern;
	char c;
	while(c = getchar()){
		if(c == '\n') break;
		s.push_back(c);		
	}
	cin >> pattern;
	int l = -1, r = -1;
	for(int i = 0; i < pattern.size(); i++){
		if(pattern[i] >= 'a' && pattern[i] <= 'z') pattern[i] -= 32;//都变成大写  
	}
	
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;//都变成大写  
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
```