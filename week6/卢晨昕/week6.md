# **week6**

## **7-1**

kmp算法是用来匹配字符串的算法，可以在线形时间内计算一个字符串是不是另一个字符串的子串

长字符串a： xyxyxyxyz

短字符串b： xy

主要分为两步走：

​        （1）对短字符串b进行自匹配，next[i] 数组记录以 i 结尾的非前缀子串与b的前缀能匹配的最长长度，即

​                next[ i ]=max { j }, 其中 j < i 并且 b[i-j+1 --> i] = b[0 --> j-1]



​            (2)对字符串 a 与 b 进行匹配，f[ i ] 表示 a 中以 i 结尾的子串与b的前缀能够匹配的最长长度，即：

​                 f[i] = max{ j },其中 j <= i 并且 a[i-j+1 --> i] = b[1 --> j]



若有 f 数组的值为b的长度，则说明b是a的子串

**注释代码：**

```c++
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int nex[1000005],f[1000005];
int ans=0;
void setup_nex(char a[])
{
	nex[0]=0;
	//j表示上一次的匹配了几个 
	for(int i=1,j=0;i<strlen(a);i++)
	{
		//不断缩小长度，直到有可以匹配上的长度
		while(j&&a[i]!=a[j])j=nex[j-1];//a[j]是上一次匹配成功的前缀的下一个  a[i]是上一个匹配成功的下一个 
        //  j代表上一次的匹配长度    nex[j-1]代表第j个数的匹配值
		//可以证明，若上一次匹配的长度为j，则若新加的字符前边的和后边的不一样，则新加的匹配值只能是next[j],next[next[j]]....中能够成立的加1
		if(a[i]==a[j])j++;
		nex[i]=j;
	}
}
void setup_f(char a[],char b[])//长   短 
{
	int len1=strlen(a);
	int len2=strlen(b);
	for(int i=0,j=0;i<len1;i++)
	{
		while(j&&a[i]!=b[j])j=nex[j-1];
		if(a[i]==b[j])j++;
		f[i]=j;
		if(j==len2)ans++;
	}
}
int main()
{
	char t[1000005],p[1000005];
	cin>>t>>p;//长   短 
	setup_nex(p);
	setup_f(t,p);
	cout<<ans;
	return 0;
}
```



## **7-2**

模拟+哈希题吧算是，打两个哈希函数，一个HASH按照题目的来，一个hash自己打，若HASH匹配上但hash没有匹配上，则说明要attention

，

时间复杂度为O(n*l)（l为字符平均长度）



## **7-3**



思路与7-1大体相同，只是需要判断一下在**短字符串**与**长字符串**匹配时是处于**长字符串**的第几个**小字符串**，且当前小字符串是否匹配过即可。时间复杂度O(len(a)+len(b)).

可以用以下代码记录小字符串的信息：

```c++
int v[1000005];//记录第i个字串是否被匹配过 
int id[1000005];//记录第i个字符属于第几个子串 
int sum=0;
void starta(char a[])
{
	int flag=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=a[i]-'A'+'a';
		}
		if(a[i]>='a'&&a[i]<='z')
		{
			if(flag==0)
			{
				sum++;
				flag=1;
			}
			id[i]=sum;
		}
		else
		{
			flag=0;
		}
	}
}
```
