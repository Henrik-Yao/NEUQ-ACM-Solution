***

# 7-1

> 编写一个程序，求出【a,b】范围内的素数。

很明显我们已经不能够再使用暴力一个一个算的低级算法了~~（除了我这个蒟蒻）~~ 

这道题是线性筛的典型题目，每一个数的倍数都不是素书，利用这一点，可以筛掉很多数字来减少运算量。

~~有种更好的方法在7-3~~

```C++
#include <iostream>
#include <cstring>
using namespace std;
int prime[11005];
int main(){
	int a,b;
	memset(prime,0,11000);
	int flag[11005];
	memset(flag,0,11000);
	int p=0;
	for(int i=2;i<=11000;i++){
		if(flag[i]==0){
			prime[p++]=i;
		}
		for(int j=i;j<=11000;j=j+i){
			flag[j]=1;
		}
	}
	while(cin>>a>>b){
		int start,end,startfind=0,endfind=0;
		for(int i=0;i<p-1;i++){
			if(prime[i]>=a&&startfind==0) {start=i;startfind=1;}
			if(prime[i]>b) {end=i-1;break;}
		}
		if(startfind!=endfind){
			cout << prime[start];
			for(int abc=start+1;abc<=end;abc++){
				cout << " " << prime[abc];		
			}
			cout << endl;
		}		
	}	
	return 0;
}
```

***

# 7-2

>你知道吗？有一种编程题需要自己推导公式，得出公式一下子就能解决问题。
具体步骤就是自己先按顺序推算几个比较小的情况，看看这几个之间有没有规律，找到规律你就能解决问题了。试着解决下面这个问题吧。有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？

这就是一道动态规划。

至于怎么推我也不会，但是确实有这个公式的。

~~其实题目的意思应该就是打表算，打表法yyds~~

```C++
#include <iostream>
using namespace std;
int step(int n){
	if(n==1) return 0;
	else if(n==2) return 1;
	else if(n==3) return 2;
	else{
		return step(n-1)+step(n-2);//状态转移
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int nu;
		cin >> nu;
		cout << step(nu);
	}
	return 0;
}
```

***

# 7-3

> 求素数的个数。本题要求编写一个程序，求1~n的素数个数。 要求至少给出两种解法，对于相同的n，给出这两种解法的结果，通过相关数据进行测试，目的是通过对比同一问题不同解法的绝对执行时间体会如何设计“好”的算法。

~~本题解法是7-1的真正解法~~

7-1的解法实际上还是有点复杂，比如说10这个数字，被2筛过一次，被5筛过一次。

所以当筛数字的时候，看一下是不是之前被除过了，被筛过的直接跳。

```C++
#include <iostream>
#include <cstring>
using namespace std;
int prime[11000005];
int flag[11000005];
int main(){
	int b;
	cin >> b;
	int p=0;
	for(int i=2;i<=b;i++){
		if(flag[i]==0){
			prime[p++]=i;
		}
		for(int j=0;j<p&&i*prime[j]<=b;j++){
			flag[i*prime[j]]=1;//这里的j其实才是开始底数
			if(i%prime[j]==0) break;//和之前完全不一样的筛法
		}
	}
	cout << p << endl;
	return 0;
}
```

***

# 7-4

> 给定三个正整数A，B和C，求A<sup>B</sup> mod C的结果，其中mod表示求余数。

这就是快速幂啊，只不过多了几次取模。

~~就是这取模的时候我不太理解，可能我数学太菜了~~。

~~不知道为什么用递归会爆段~~

一种数学的公式是 (a+b)Modc=aModc+bModc，乘法也可。

```C++
#include <iostream>
using namespace std;
long long c;
long long calc(long long a, long long b){
	long long ans = 1;
	while(b>0){
		if (b%2==1) ans = (ans * a) % c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
    long long a,b;
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a >> b >> c;
        cout << calc(a,b) << endl;
    }
    return 0;
}
```

