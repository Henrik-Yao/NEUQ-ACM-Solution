# Week 7 题解



## 7-1 词典

---

我的办法应该相当得暴力。。。开了一个超级大的桶（小一个数量级就会因为哈希冲突过不了）。这个桶用于存放加密的单词对应的哈希值。用map使得哈希值和解密后的单词一一对应。再后续的输入中直接判断在不在桶里就行了。应该比较节省时间。



## 7-2 神秘密码

---

自己有个大体的思路，但难以代码实现。看了某谷dalao的代码感觉神清气爽。在读入过程中就用递归完成了要求QAQ.就是如果遇到左括号就输入一次循环次数n，再输入一个字符串，进行n次拼接，遇到右括号就返回。代码精简又好懂，献上我的膝盖。



## 7-3 删除公共字符串

---

在输入上面卡了好久555.还是用了个桶（不过反正用到的字符也不多，可以开得很小，直接存ASCII值就行了），输出的时候，如果当前的字符对应的ASCII值在桶里的话就continue掉。



## 7-4 最长有序子序列

---

人的认识是不断发展的。暑假写百题写到导弹拦截那一题的时候感觉太难了，现在感觉好理解多了。就dp一下呗。。。



## 7-5 01背包问题

---

今天头一次接触背包问题。是开了一个dp二维数组，横轴上是提供的背包容量，纵轴上是不同的物品。在每个坐标处只需要判断是否要将物品放入背包。

核心代码：

···

	for(i=1;i<=n;i++)
		{
			for(j=1;j<=bag;j++)
			{
				if(j<w[i])
				dp[i][j]=dp[i-1][j];
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
					ma=max(ma,dp[i][j]);
				}
				//cout<<dp[i][j]<<' ';
			}
			//cout<<endl;
		}

···

