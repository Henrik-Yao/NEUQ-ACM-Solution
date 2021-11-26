# 7-1 词典

简单的字符串匹配，运用string会简单很多。

# 7-2 神秘密码

一开始不会写，洛谷上看的：https://www.luogu.com.cn/problem/solution/P1928

方法一：这种方法的精妙之处在于read()在读入时并未将'['与D作为字符串的一部分，而是直接将其解压后接入原字符串，相比整体读入后再处理，处理难度大大下降。

```cpp
string read()
{
	int n;
	string s="",s1;
	char c;
	while (cin>>c)//一直读入字符，直到Ctrl+z
	{
		if (c=='[')
		{
			cin>>n;//读入D
			s1=read();//读入X
			while (n--) s+=s1;//重复D次X
            //注：上面不能写成while (n--) s+=read();
		}
		else 
		{
			if (c==']') return s;//返回X
		    else s+=c;//如果不是'['和']'，那就是X的一个字符，所以加进X
		}
	}
}
```

方法二：常规的读入后再处理，主体思想一样

```cpp
for(int i=0;i<s.length();i++)
    {
        if(s[i]=='[')        //找左括号的位置 
        {
            start[++sum]=i;
        }
    }
    for(int i=sum;i;i--)    //从最后一个左括号开始做，因为最后一个括号内肯定没有括号了 
    {
        ended=2;num=0;temp.clear();now.clear();    //ended=2，因为还要加上左右括号 
        for(int j=start[i]+1;s[j]!=']';j++)
        {
            if(s[j]>='0'&&s[j]<='9')    //要把串复制几遍 
            {
                num=num*10+s[j]-'0';
            }
            else
            {
                temp+=s[j];
            }
            ended++;        //右括号的位置 
        }
        for(int j=1;j<=num;j++)        //将字串解压 
        {
            now+=temp;
        }
        s.erase(start[i],ended);        //将左右括号以及之间的子串删掉 
        s.insert(start[i],now);        //插入扩展开的串 
    }
```

我认为本题目的难点在于'['后进行解压后并将其接入原字符串中。

# 7-3 删除公共字符串

易错点有两个：

1、多组数据输入这个输入条件容易被忽视。

2、字符串B中会有空格所以不能直接用string B,cin>>B;应该要用getline(cin,B)。

# 7-4 最长有序子序列

简单的dp算法，注意一点，dp[n]处不一定是最大值。

# 7-5 0-1背包问题

注意：

```in
for (j = c; j >= weight[i]; j--)
			{
				if (allweightvalue[j - weight[i]] + value[i] > allweightvalue[j]) allweightvalue[j] = allweightvalue[j - weight[i]] + value[i];
			}
			//for (j = 0; j <= c; j++)
				//cout << "allweightvalue[" << j << "]: " << allweightvalue[j] << endl;
			//cout << endl;
```

这一段进行处理时，应由大到小，不然会对同一物品进行重复放入。