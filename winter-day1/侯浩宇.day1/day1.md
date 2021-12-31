### **7-3 特殊约瑟夫问题**

用线性表存储，按题目要求，删除对应元素，当表内无元素时停止。

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m,k,nextt[1001],head[1001],p=0;
int nex(int n1,int n2){
	for(int i=1;i<n2;i++)
	n1=nextt[n1];
	return n1;
}
int hea(int n1,int n2){
	for(int i=1;i<n2;i++)
	n1=head[n1];
	return n1;	
}
void f1(int number);
void f2(int number);
int main(){ 
	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)
//	a[i]=i;
	nextt[1]=n;
	for(int i=n;i>1;i--)
	nextt[i]=i-1;
	head[n]=1;
	for(int i=1;i<n;i++)
	head[i]=i+1;
	f1(1);
	return 0;
}
void f1(int number){
	int ans;
	ans=nex(number,m);
	cout<<ans<<" ";p++;
	nextt[head[ans]]=nextt[ans];
	head[nextt[ans]]=head[ans];
	if(p<n)f2(nextt[ans]);
}
void f2(int number){
	int ans;
	ans=hea(number,k);
	cout<<ans<<" ";p++;
	nextt[head[ans]]=nextt[ans];
	head[nextt[ans]]=head[ans];
	if(p<n)f1(head[ans]);
}
```

### **7-4 程序设计综合实践 1.4**

将数据排序后存入链表，在将奇偶数分别存储。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[100000],a1[100000],a2[100000];
	int i1,i2,i;
	i1=i2=i=0;
	while(1)
	if(!(cin>>a[i++])) break;
	sort(a,a+i-1);
/**/for(int j=0;j<i-1;j++){
	cout<<a[j];
	if(j<i-2)cout<<"->";
}
	cout<<endl;
	for(int j=0;j<i-1;j++){
		if(a[j]%2)a1[i1++]=a[j];
		else a2[i2++]=a[j];
	}
	for(int j=0;j<i1;j++){
		cout<<a1[j];
		if(j<i1-1)cout<<"->";
	}
	cout<<endl;
	for(int j=0;j<i2;j++){
		cout<<a2[j];
		if(j<i2-1)cout<<"->";
	}
	return 0;
}
```

### **7-5 括号匹配**

每个左括号对应自己的右括号，有未对应的，计算差值，左右分别加括号。

```c++
for(int i=0;i<a.length();i++){
	if(a[i]=='(')n++;
	else if(n==0)n1++;
	else n--;
}
n+=n1;//n不为0时，n1为所需左括号数，n为所需右括号数
```

```c++
#include<bits/stdc++.h>
using namespace std;
string a;int n=0,n1=0;
void ppp(){
	for(int i=0;i<n1;i++)cout<<"(";
	for(int i=0;i<a.length();i++)
	cout<<a[i];
	for(int i=0;i<n-n1;i++)cout<<")";
	cout<<endl;	
}
void pp(){
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(')n++;
		else if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(!n) cout<<"Match"<<endl;
	else{
		cout<<n<<endl;
		ppp();
	}
}
int main(){
	while(1){
	if(getline(cin,a)){
		pp();
		for(int i=0;i<a.length();i++)
		a[i]='\0';
	}
	else break;
	}
	return 0;
}
```

### **7-6 字符串对称**

正反2个链表一一比对。

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,a1,a2;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]!=a[a.length()-i-1]){
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"yes"<<endl;
	return 0;
}
```

### **7-7 魔王语言解释**

1. B->tAdA  
2. A->sae
3. (θδ1δ2...δn)->θδnθδn-1...θδ1θ

```c++
#include<bits/stdc++.h>
using namespace std;
string a,ans;
void f1(){
	ans+="tsaedsae";
}
void f2(){
	ans+="sae";
}
void f3(int beginn){
	int endd,i;
	for( i=beginn;i<a.length();i++){
	//	cout<<1;,cout<<beginn
		while(a[i]==')')break;
	}endd=i-beginn;
	//ans+=a[beginn];
	for(int i=endd-1;i>beginn;i--){
		if(a[i]=='B')f1();
		if(a[i]=='A')f2();
		if(a[i]>='a'&&a[i]<='z')ans+=a[i];
		if(a[i]=='('){
			f3(i);
			while(a[i]!=')')i++;
		}
		ans+=a[beginn];
	}	
}
int main(){
	cin>>a;
    ans="";
	for(int i=0;i<a.length();i++){
		if(a[i]=='B')f1();
		if(a[i]=='A')f2();
		if(a[i]=='('){
			f3(i+1);
			while(a[i]!=')')i++;
		}
	}		
	cout<<ans<<endl;
	return 0;
}
```

### **7-8 括号配对**

与第5题类似，做三次匹配即可。

```c++
#include<bits/stdc++.h>
using namespace std;
string a;
bool p=1;
void pp1(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(')n++;
		else if(a[i]==')')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
void pp2(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='[')n++;
		else if(a[i]==']')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
void pp3(){
	int n,n1;
	n=n1=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='{')n++;
		else if(a[i]=='}')
		if(n==0)n1++;
		else n--;
	}
	n+=n1;
/**/if(n){
		p=0;return;
	}
}
int main(){
	cin>>a;
	pp1();
	pp2();
	pp3();
	if(p)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
```

### **7-10 列车车厢重排**

开一个线性表从前往后，递减，无法递减时，开一个新线性表，

输出第一个线性表，好线性表总数

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100],minn=100,ans=0,b[100][100],b1=0;
	bool p[100],p1=1;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i],p[i]=1;
	while(p1){
		minn=100;int j=0;
		for(int i=0;i<n;i++){
			if(p[i])
			if(minn>a[i]){
			minn=a[i],p[i]=0;
            
			b[ans][j++]=a[i];
			if(a[i]==1) b1=ans;
			}
		}
		ans++;
		for(int i=0;i<n;i++){
			if(p[i]){p1=1;break;}
			else p1=0;
		}
	}
	int i=0;
	while(b[b1][i]){
        cout<<b[b1][i++];
        if(b[b1][i])cout<<" ";
    }
	cout<<endl<<ans<<endl;
	return 0;
}
```

