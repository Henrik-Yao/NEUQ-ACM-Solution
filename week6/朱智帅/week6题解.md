# 7-1 字符串模式匹配

题目在使用基础KMP算法时，要是使用char时记得提前进行len1，len2的赋值，如果全部采用strlen会严重超时，还有书上的从1开始会出现答案错误，不知道为什么。



# 7-2 妈妈再也不用担心我被拖库了

一道非常折磨的题，主要运用哈希表相关知识，string类可以简化代码，注意在书写过程中记住逐段编译检查，不然容易最后成一团糊(血泪教训![img](file:///C:\Users\86187\AppData\Local\Temp\SGPicFaceTpBq\8728\0F0B6C7A.png))，题目本身并没有太大难度，但细节很多，因此容易出错。下面我的一些总结：

1、首先是题目中关于密码的处理是不区分大小写的(我偷懒没专门写函数进行求哈希的处理，直接Ctrlc+v自己写的另一段代码结果少粘了一段花了我好长时间才看出来。)大家自己写的时候不要偷懒。

2、记住要用有意义的变量名，否则特别麻烦，还有   -=   会出现莫名的错误，建议不要偷懒写全。

3、密码分四段进行处理的操作有多种，这里列举一种：

```out
len[4] = passwordlen / 4;
len[3] = (passwordlen - len[4]) / 3;
len[2] = (passwordlen - len[3] - len[4]) / 2;
len[1] = passwordlen - len[2] - len[3] - len[4];
int Strat[6];//四个区域用来加和的起始位置记录。
Strat[1] = 0, Strat[2] = len[1], Strat[3] = len[1] + len[2], Strat[4] = len[1] + len[2] + len[3], Strat[5] = len[1] + len[2] + len[3] + len[4];
```

对了，我的代码里内附有我的测试代码，还有问题的同学可以参考一下。

# 7-3 字符串个数匹配

本题目的最大问题在于预处理中运行超时的问题，在预处理中A字符串我只录入字母（不区分其大小写）（注意若在预处理过程中将全部字母提前变为小写会出现运行超时，这部分很恶心![img](file:///C:\Users\86187\AppData\Local\Temp\SGPicFaceTpBq\148\1492D96A.png))，其次输入B时建议采用string进行，另外不知道是不是由于我电脑软件内部的问题-1<B.size()判false，注意要用int lenB=B.size()才行（非常好奇为什么？![img](file:///C:\Users\86187\AppData\Local\Temp\SGPicFaceTpBq\148\14959454.jpg))
