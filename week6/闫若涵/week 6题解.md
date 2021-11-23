### week 6题解

用KMP算法求解的经典题目。

创建noext[]数组，next数组不止可以返回下标，还可以匹配最长前缀字符

当两字符串不相等时回溯，返回next数组的下标

代码如下：

```c++
#include<bits/stdc++.h>
#define MAXSIZE  100001
using namespace std;
string s,t; 
void GetNext(int next[])	
{
	int j,k;
	j = 0;k = -1; 
	next[0] = -1;
	while (j < t.length())
	{	
		if ( k == -1 || t[j] == t[k]) 	
		{	
			j++;
			k++;
			next[j] = k;
       	}
       	else
		{
		k = next[k];	
		}
	}
}
int  KMP()  
{
	int count = 0;
	int next[MAXSIZE],i = 0,j = 0;
	GetNext(next);
	while (j < s.length()) 
	{
		if (i == -1 || s[j] == t[i]) 
		{
			i++;j++;  			
		}
		else i = next[i]; 
		if (i == t.length())    		
		count++;	
    }
   
	return count;
}
int main()
{
	cin >> s >> t;
	int m = KMP();
	cout << m << endl; 
}

```

