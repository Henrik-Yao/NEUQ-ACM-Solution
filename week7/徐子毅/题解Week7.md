***

# 7-1

> 你刚从滑铁卢搬到了一个大城市，这里的人们讲一种难以理解的外语方言。幸运的是，你有一本字典来帮助你理解它们。
>
>
>### 输入格式:
> 输入第一行是正整数N和M,后面是N行字典条目（最多10000条），然后是M行要翻译的外语单词（最多10000个）。每一个字典条目都包含一个英语单词，后面跟着一个空格和一个外语单词。 输入中的每个单词都由最多10个小写字母组成。
>### 输出格式:
> 输出翻译后的英文单词，每行一个单词。非词典中的外来词汇输出“eh”。

我是fw,我不会map。

```C++
#include <iostream>
#include <cstring>
using namespace std;
struct dictory{
    string ori;
    string hon;
};
int main(){
    int n,m;
    cin >> n >> m;
    dictory dic[n];
    for(int i=0;i<n;i++){
        cin >> dic[i].ori >> dic[i].hon;
    }
    string honlan;
    for(int abc=0;abc<m;abc++){
        bool found=false;
        cin >> honlan;
        for(int i=0;i<n;i++){
            if(dic[i].hon==honlan) {cout << dic[i].ori << endl;found=true;break;}
        }
        if(!found) cout << "eh" << endl;
    }
    return 0;
}
```

***

# 7-2

> 传说二战时X国收到了上帝的一串密码，只有解开密码，才能阻止战争的继续进行，世界才会恢复和平。解开密码的第一道工序就是解压缩密码，上帝对于连续的若干个相同的子串"X"会压缩为"[DX]"的形式(D是一个整数且1<=D<=99),比如说字符串"CBCBCBCB"就压缩为"[4CB]"或者"[2[2CB]]",类似于后面这种压缩之后再压缩的称为二重压缩。如果是"[2[2[2CB]]]"则是三重的。现在我们给你上帝发送的密码，请你对其进行解压缩。
>### 输入格式:
>一个字符串
>
>### 输出格式:
>一个字符串

~~我这道题pta过了但是luogu没过然后我就发现有点小bug,最后改了~~。

这道题我第一次尝试找括号，左边第一个[和右边第一个]配对，然后递归找[]里面的。后来发现这样不行因为有些样例比如说是3[3AC]BB[2DE]，这样用左右配对会出bug.

于是就需要遍历，第二次尝试，从左往右逐渐遍历，遍历到第一个就找[]里的，但这样应对不了二重的解压缩，于是就需要找相对应的]来匹配。

于是就需要一个计数器，在遍历']'的时候要寻找下[的次数，否则会无法应对二重。

另外，每一次返回[]内的数，要检查一下[]里面是否是已经解压的。

比如2[2[2AC]]，不进行检查的话十分容易出现2ACAC2ACAC这个结果。

具体思路就是找到了[]，开拆，拆了[前的[]中的和]后的，然后就把[]中间的给unpack了，再把三段拼接起来，注意遍历的下标的位置需要发生改变。

```C++
#include <iostream>
using namespace std;
string unpack(string str){
	bool isclean=true;
	int i=0,j;
	for(i=0;i<str.size();i++){
		if(str[i]=='['){
			isclean=false;
			break;
		}
	}
	if(isclean){
		int doublestatus=1;
		string newstr="",cutstr="";
		if(str[0]>='0'&&str[0]<='9'){
			if(str[1]>='0'&&str[1]<='9'){
				doublestatus=((int)(str[0]-'0'))*10+(int)(str[1]-'0');
				for(int a=2;a<str.size();a++) cutstr+=str[a];
				for(int a=1;a<=doublestatus;a++) newstr+=cutstr;
				return newstr;
			}else{
				doublestatus=(int)(str[0]-'0');
				for(int a=1;a<str.size();a++) cutstr+=str[a];
				for(int a=1;a<=doublestatus;a++) newstr+=cutstr;
				return newstr;
			}
		}else return str;
	}else{
		string newstr="",shouldunpackstr="";
		for(int p=0;p<str.size();p++){
			int intoleft=0;
			shouldunpackstr="";
			if(str[p]!='[') newstr+=str[p];
			else if(str[p]=='['){
				intoleft=1;
				for(j=p+1;j<str.size();j++){
					if(str[j]=='[') intoleft++;
					if(str[j]==']') intoleft--;
					if(str[j]==']'&&intoleft==0) break;
					shouldunpackstr+=str[j];
				}
				newstr+=unpack(shouldunpackstr);
				p=j;
			}
		}
		return unpack(newstr);
	}
}
int main(){
	string strori;
	cin >> strori;
	cout << unpack(strori) << endl;
	return 0;
}
```

~~luogu能AC~~

***

# 7-3

>输入两个字符串，从第一个字符串中删除第二个字符串中的所有字符。例如，输入“They are students.”和“aeiou”，则删除之后的第一个字符串变成“Thy r stdnts”。
>### 输入格式:
>输入包含多组测试，每个测试输入包含两个字符串。
> ### 输出格式:
>输出删除后的字符串。



~~谢谢你，多组数据，让我白debug了好久~~

如果反复查找时间复杂度为O(n^2)会有点久。

可以做一个hash表，第二串数据输入进去时，因为一个字符对应一个ASCLL码，所以可以标记其为1。

再遍历第一串字符串，发现hash为1的直接跳。

```C++
#include <iostream>
#include <cstring>
using namespace std;
int hashing[257];
int main(){
	string strori,strdel;
	while(getline(cin,strori)){
	    getline(cin,strdel);
    	for(int i=0;i<257;i++) hashing[i]=0;
	    for(int i=0;i<strdel.size();i++){
    		hashing[(int)strdel[i]]=1;
    	}
    	for(int i=0;i<strori.size();i++){
    		if(hashing[(int)strori[i]]==0) cout << strori[i];
    	}
        cout << endl;
    }
	return 0;
}
```

***

# 7-4
>对于给定一个数字序列 (a <sub>1</sub>，a<sub>2</sub>，…，a <sub>n</sub>) ，如果满足a 
><sub>1</sub><a <sub>2</sub><…<a <sub>3</sub> ，则称该序列是有序的。若在序列(a <sub>1</sub> ，a <sub>2</sub> ，…，a <sub>n</sub>) 中删除若干元素得到的子序列是有序的，则称该子序列为一个有序子序列。有序子序列中长度最大的即为最长有序子序列。
>例如，(1，3，5)、(3，5，8)、(1，3，5，9)等都是序列 (1，7，3，5，9，4，8) 的有序子序列；而(1，3，5，9)、(1，3，5，8)、(1，3，4，8)都是序列 (1，7，3，5，9，4，8)的一个最长有序子序列，长度为4。
>请编写程序，求出给定数字序列中的最长有序子序列的长度。
>
>### 输入格式:
>首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据第一行输入一个整数 n（1≤n≤1000），第二行输入n个整数，数据范围都在[0，10000]，数据之间以一个空格分隔。
>### 输出格式:
>对于每组测试，输出n个整数所构成序列的最长有序子序列的长度。每两组测试的输出之间留一个空行。


经典DP题，时间复杂度为O(n^2)。

设一个数组为dp,代表了这个数字前的最大递增子序列。

dp初始值固然为1~~（我一开始傻了全设成了0）~~,从0开始遍历，往前找一个比自己小的数字。

状态转移方程为dp[i]=max(dp[i],dp[j]+1)

```C++
#include <iostream>
#include <cstring>
using namespace std;
int dp[1005],a[1005];
int main(){
	int T;
	cin >> T;
	for(int abc=1;abc<=T;abc++){
	    int n;
		int _max=1;
	    cin >> n;
		for(int i=0;i<n;i++) {cin >> a[i];dp[i]=1;}
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
		        if(a[i]>a[j]) {dp[i]=max(dp[i],dp[j]+1);}
       		}
   		}
        for(int i=0;i<n;i++){
            if(dp[i]>_max) _max=dp[i];
        }
		cout << _max << endl;
        if(abc!=T) cout << endl;
	}
}
```

***

# 7-5

~~谢谢你，多组数据，让我白debug了好久~~
>给定n种物品（每种仅一个）和一个容量为c的背包，要求选择物品装入背包，使得装入背包中物品的总价值最大。
>### 输入格式:
>测试数据有多组，处理到文件尾。每组测试数据输入3行，第1行为两个整数n（1≤n≤400）和c (1≤c≤1500)，分别表示物品数量与背包容量，第二行为n个物品的重量w 
<sub>i</sub>（1≤i≤n），第三行为这n个物品的价值v <sub>i</sub> （1≤i≤n）。物品重量、价值都为整数。
>### 输出格式:
>对于每组测试，在一行上输出一个整数，表示装入背包的最大总价值（结果保证在int范围内）。

因为无意义的反复debug<sub>~~（没看到多组数据ASWLAAAAA）~~</sub>,所以写了两种。

1、费时间，省空间：

这种思路是把以背包容量为主体，首先就是判断当前的背包容量能否装得下这个物品，如果装不下不管它。如果能装，就判断装和不装那种情况更好，不装就是当前背包容得下最大物品的价值，装就是当前背包剩余-体积这个背包的最大价值加上现在的价值。

```C++
#include <iostream>
using namespace std;
int things,maxkilo,bagrommax[1505];
int main()
{
    while(cin >> things >> maxkilo){
        for(int i=0;i<=maxkilo+3;i++) bagrommax[i]=0;
    	int value[things+1],kilo[things+1];
    	for(int i=1;i<=things;i++) cin >> kilo[i];
    	for(int i=1;i<=things;i++) cin >> value[i];
    	kilo[0]=value[0]=0;
    	for(int i=1;i<=things;i++){
    		int j;
    		for(j=maxkilo;j>0;j--){
    			if(kilo[i]<=j) bagrommax[j]=max(bagrommax[j],bagrommax[j-kilo[i]]+value[i]);
    		}
    	}
    	cout << bagrommax[maxkilo] << endl;
    }
    return 0;    
}
```

2、省时间，费空间：

这种思路是常见的开二维数组的思想，以物品为主体。一个下标表示剩余容量，一个下标表示物品。每个dp代表着当前背包容量装前几个物品的最大价值。可见0容量和0物品的价值全部为0。判断时，如果背包的容量比当前物品小了，那这个格子的值为前面物品放入这个背包的最大价值，如果背包能装下这个物品，就判断装不装更有价值，不装同上，也是为前面物品放入这个背包的最大价值，如果装，就是要前面物品放入体积-当前物品这个容量的背包加上当前最大值。

```C++
#include <iostream>
using namespace std;
int dp[1505][405];
int value[405],kilo[405];
int main(){
	int nimotsu;
	int maxkilo;
	while(cin>>nimotsu>>maxkilo){
        for(int i=0;i<405;i++){value[i]=0;kilo[i]=0;}
    	value[0]=0;
    	kilo[0]=0;
    	for(int i=1;i<=nimotsu;i++) cin >> kilo[i];
    	for(int i=1;i<=nimotsu;i++) cin >> value[i];
    	for(int i=0;i<=maxkilo;i++) dp[i][0]=0;
    	for(int i=0;i<=nimotsu;i++) dp[0][i]=0;
     	for(int i=1;i<=maxkilo;i++) {
    		for(int j=1;j<=nimotsu;j++) {
    			if(kilo[j]>i) dp[i][j]=dp[i][j-1];
    			else{
    				if(dp[i][j-1]>dp[i-kilo[j]][j-1]+value[j]) dp[i][j]=dp[i][j-1];
    				else dp[i][j]=dp[i-kilo[j]][j-1]+value[j];
    			}
    		}
    	}
	cout << dp[maxkilo][nimotsu] << endl; 
    }
	return 0;
}
```

##### ~~审题不谨慎，debug两行泪。~~

