# WEEK 7 题解

### 7-1 词典

本题比较简单，可以通过map来进行存储，一切问题便迎刃而解了

```C++
#include <bits/stdc++.h>
using namespace std;
map<string,string>word;
int N,M;
int main()
{
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		string string1,string2;
		cin>>string1>>string2;
		word[string2]=string1;
	}
	for(int i=0;i<M;i++)
	{
		string remp;
		cin>>remp;
		if(word.count(remp))
		cout<<word[remp];
		else
		cout<<"eh";
		if(i!=M-1)
		cout<<endl;
	}
	return 0;
}

```

### 7-2 神秘密码

本题解来自洛谷搬运，基本思路通过递归来将加密密码进行依次解压，通过识别关键字符'['来达到效果 

```C++
#include <bits/stdc++.h>
using namespace std;
string unpack()
{
    string tar,s1;
    char ch;//输入暂时字符
    int n;//[括号后的第一个数字
    while(cin>>ch)//循环输入字符（Ctrl+z）
    {
        if(ch=='[')
        {
            cin>>n;
            s1=unpack();//暂时存放递归的字符串
            for(int i=0;i<n;i++)
            tar+=s1;//tar为主串每次递归的主串
        }
        else
        {
            if(ch==']')
            return tar;
            else
            tar+=ch;
        }
    }
}
int main()
{
    cout<<unpack();
    return 0;
}
```

### 7-3 删除公共字符

思路很简单，关键是 **空格不要人为删除！**

*呜呜这道题考试的时候交了20多次，考完以后被董神嘲笑，岂可修！*

```C++
#include <bits/stdc++.h>
using namespace std;
string tar;//目标
string str;//模式串
//int len1;//目标长度
//int len2;//模式串长度
//map<char,bool>judge;//判断是否重复
int main() {
	while(getline(cin,tar)&&getline(cin,str)) {
		
		map<char,bool>judge;
		int len1=tar.size();
		int len2=str.size();
		for(int i=0; i<len2; i++) {
			judge[str[i]]=1;//重复元素标记
		}
		for(int i=0; i<len1; i++) {
			char ch=tar[i];
			if(judge[ch]) continue;
			cout<<tar[i];
		}
		cout<<endl;
	}
	return 0;
}

```

### 7-4 最长有序子序列

经典的KMP算法题，代码写起来有点麻烦，但是除了KMP核心以外按步模拟就可以了

```C++
#include <bits/stdc++.h>
using namespace std;
int sum[10000000];
int a[100000000];
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int remp;
        cin>>remp;
        for(int j=0;j<remp;j++)
        {
            cin>>a[j];
        }
        sum[0]=1;
        for(int j=1;j<remp;j++)
        {
            sum[j]=1;
            for(int k=0;k<j;k++)
            {
                if(a[k]<a[j])
                sum[j]=max(sum[k]+1,sum[j]);
            }
        }
        sort(sum,sum+remp);
        cout<<sum[remp-1];
        memset(sum,0,1000);
        memset(a,0,1000);
        cout<<endl;
        if(i!=num-1)
        cout<<endl;
    }



    return 0;
}
```

### 7-5 01背包

创建一个二维数组，然后通过递推来实现结果

![image-20211126193257286](C:\Users\JINTIAN\AppData\Roaming\Typora\typora-user-images\image-20211126193257286.png)

```C++
#include <bits/stdc++.h>
using namespace std;
int dp[10000][10000]; //前者为背包物品数目，后者为总容量，数组存的是此时的最大价值
int value[10000];
int room[10000];
int main()
{
    int num, space;
    while (cin >> num >> space)
    {
        for (int i = 1; i <= num; i++)
            cin >> room[i];
        for (int i = 1; i <= num; i++)
            cin >> value[i];
        for (int i = 1; i <= num; i++) //i的值为物品编号
        {
            for (int j = 1; j <= space; j++) //j的值是背包的容量
            {
                if (room[i] > j) //背包放不下
                    dp[i][j] = dp[i - 1][j];
                else //背包放得下
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - room[i]] + value[i]);
            }
        }
        int max1 = 0;
        for (int i = 1; i <= num; i++)
        {
            for (int j = 1; j <= space; j++)
            {
                max1 = max(dp[i][j], max1);
            }
        }
        cout << max1<<endl;
        for (int i = 1; i <= num; i++)
        {
            value[i] = 0;
            room[i] = 0;
            for (int j = 1; j <= space; j++)
            {
                dp[i][j] = 0;
            }
        }
    }
    return 0;
}
```

