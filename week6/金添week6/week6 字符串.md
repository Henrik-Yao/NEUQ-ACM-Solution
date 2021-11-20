# week6 字符串

### 7-1 KMP算法

首先要明白next数组的核心含义：

+ 第一点 ：next数组是指前缀和，是前方数组的重复串的最大长度

+ 第二点 ：next数组是与主串匹配时，如不符合，跳到该下标继续匹配

  ```C++
  #include <bits/stdc++.h>
  using namespace std;
  char tar[1000000];//记录主串
  char ch[1000000];//记录模式串
  int next1[1000000];
  long long sum=0;
  void getnext() { //求模式串的next值
  	int remp1,remp2;
  	remp1=-1;
  	remp2=0;
  	next1[0]=-1;
  	int jtdsb=strlen(ch);
  	while(remp2<jtdsb) {
  		if(remp1==-1||ch[remp1]==ch[remp2]) {
  			next1[++remp2]=++remp1;
  		} else {
  			remp1=next1[remp1];
  		}
  	}
  }
  int KMP() {
  	int remp1=0;//主串指针
  	int remp2=0;//模式串指针
  	int jtdsb=strlen(tar);
  	int jt=strlen(ch);
  	while(remp1<jtdsb) {
  		if(remp2==-1||tar[remp1]==ch[remp2]) {
  			remp1++;
  			remp2++;
  		} else {
  			remp2=next1[remp2];
  		}
  		
  		if(jt==remp2) {
  			sum++;
  			remp2=next1[remp2];
  		}
  	}
  	return sum;
  }
  int main() {
  	cin>>tar;
  	cin>>ch;
  	getnext();
  	cout<<KMP();
  	return 0;
  }
  ```

  

### 7-2 拖库

此题只需按照题目的条件依次模拟，推荐用map求解，可以减少定义的变量数，我写的笨办法/笑哭，导致写了150行，但是思路还是很直接的 。

```C++
#include <bits/stdc++.h>
using namespace std;
map<string,string>user;//定义一个用户的map
//map<string,string>Hash;//记录每一个字符串对应的哈希值
int len1,len2,len3,len4;//临时记录其四个小字符串的长度
string runhash(string code) {
	int len=code.size();
	int remp=len%4;
	switch(remp) {
		case 0: {
			len1=len2=len3=len4=len/4;
			break;
		}
		case 1: {
			len1=len/4+1;
			len2=len3=len4=len/4;
			break;
		}
		case 2: {
			len1=len2=len/4+1;
			len3=len4=len/4;
			break;
		}
		case 3: {
			len1=len2=len3=len/4+1;
			len4=len/4;
			break;
		}//记录其字符串分配情况
	}
	//for(i=0;i<temp;++i) len[i]=n/4+1;
	//for(int i=temp;i<4;++i) len[i]=n/4;
	 
	int sum[5]= {0,0,0,0,0}; //记录hash
	for(int i=0; i<len1; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]-'A'+'a';//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-'a'+10;
			sum[1]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-'0';
			sum[1]+=shu;
		}
	}
	for(int i=len1; i<len1+len2; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[2]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[2]+=shu;
		}
	}
	for(int i=len1+len2; i<len1+len2+len3; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[3]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[3]+=shu;
		}
	}
	for(int i=len1+len2+len3; i<len1+len2+len3+len4; i++) { //开始分步计算哈希值

		if(code[i]<='Z'&&code[i]>='A')
			code[i]=code[i]+32;//转换为小写
		if(code[i]<='z'&&code[i]>='a') {
			int shu=code[i];
			shu=code[i]-87;
			sum[4]+=shu;
		}
		if(code[i]<='9'&&code[i]>='0') {
			int shu=code[i];
			shu=code[i]-48;
			sum[4]+=shu;
		}
	}
	for(int i=1; i<=4; i++) {
		sum[i]=sum[i]%36;
	}
	string zan;
	for(int i=0; i<4; i++) {
		char ch;
		if(sum[i+1]<=9&&sum[i+1]>=0) {
			ch=sum[i+1]+'0';
//			zan[i]=ch;
			zan+=ch; 
		}
		if(sum[i+1]<=36&&sum[i+1]>9) {
			ch=sum[i+1]-10+'a';
//			zan[i]=ch;
			zan+=ch; 
		}
	} 
	return zan;
}
int main() {
	int num;
	cin>>num;
	for(int i=0; i<num; i++) {
		char ch;
		cin>>ch;
		string str;//用户名
		string remp;//用户密码
		cin>>str;
		cin>>remp;
		if(ch=='R') {
//			string a=user[str];
			if(user.count(str))//count测其中有没有东西 
				cout<<"Repeated!";//之前已经注册过
			else {
				user[str]=remp;//若无注册过，将该元素存入map中
				cout<<"Signed!";
//				Hash[str]=runhash(remp);//对其密码进行规划
			}
		}
		if(ch=='L') {
//			string de=runhash(remp);//登录密码的哈希代码
//			string zh=Hash[str];//该用户的哈希代码
//			string mi=user[str];//该用户的原密码
			if(user[str]==remp) {
				cout<<"Success!";
			} else if(runhash(user[str])==runhash(remp)) {
//				cout<<user[str]<<" "<<remp<<"\n";
				cout<<"Attention!";
			} else {
				cout<<"Failed!";
			}
		}
		cout<<"\n"; 
	}
	
	return 0;
}
```



### 7-3 字符字串

思路和题目1相似，注意字符子串划分的方法，否则达不到题目预期效果

```C++
#include <bits/stdc++.h>
using namespace std;
char tar[1000000];//记录主串
char ch[1000000];//记录模式串
int next1[1000000];
int	length[1000001];//记录各个小字符串的长度
int num=0;//记录总共小字符串的个数
int cou=0;//记录KMP搜索时进行到哪个小字符串
long long sum=0;
int sen=0;
void getnext() { //求模式串的next值
	int remp1,remp2;
	remp1=-1;
	remp2=0;
	next1[0]=-1;
	int jtdsb=strlen(ch);
	while(remp2<jtdsb) {
		if(remp1==-1||ch[remp1]==ch[remp2]) {
			next1[++remp2]=++remp1;
		} else {
			remp1=next1[remp1];
		}
	}
}
int KMP() {
	int remp1=0;//主串指针
	int remp2=0;//模式串指针
	int jtdsb=strlen(tar);
	int jt=strlen(ch);
	while(remp1<jtdsb) {
		if(remp1<length[cou]) {
			if(remp2==-1||tar[remp1]==ch[remp2]) {
				remp1++;
				remp2++;
			} else {
				remp2=next1[remp2];
			}

			if(jt==remp2) {
				sum++;
				remp2=next1[remp2];
				remp1=length[cou];
				cou++;
				sen++;
			}
		} 
			else {
			remp1=length[cou];
			cou++;
			}
	}
	return sen;
}
int main() {
	cin.getline(tar,1000000000);
	cin.getline(ch,10000);
	int l1=strlen(tar);
	int l2=strlen(ch);
	for(int i=0; i<l2; i++) {
		if(ch[i]<='Z'&&ch[i]>='A')
			ch[i]=ch[i]+32;
	}
	/*	         分割线                    */
	for(int i=0; i<l1; i++) {
		if(tar[i]<='Z'&&tar[i]>='A')
			tar[i]=tar[i]+32;
		if(!((tar[i]<='z'&&tar[i]>='a')))
			tar[i]=' ';
	}
	/*	         分割线                    */
	for(int i=0; i<l1; i++) {
		if((tar[i]>='a'&&tar[i]<='z')&&(!(tar[i+1]>='a'&&tar[i+1]<='z')))
			length[num++]=i+1;
	}
	/*	         分割线                    */
	getnext();
	cout<<KMP();
	return 0;
}
```

