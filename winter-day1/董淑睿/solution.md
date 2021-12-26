# solution
## 7-1 动态区间求和
树状数组小常数可以做
## 7-2 小明打字
链表模拟
记录尾巴在哪里
头默认为0
## 7-3 特殊约瑟夫问题
链表模拟
## 7-4 程序设计综合实践 1.4
跟着题目模拟
## 7-5 括号匹配
用stack，最后的形式一定是)))(((((这样，也可能没有。
top=0即匹配，否就强行加字符匹配)))((((。很容易看出怎么加。
## 7-6 字符串对称
用stack，奇数串的时候要特判掉中间字符。用起来当然不如for好用。
## 7-7 魔王语言解释
阅读理解题
## 7-8 括号配对
和括号匹配一样
## 7-9 银行排队问题之单窗口“夹塞”版
模拟捏。正在办业务的人有一段占用时间，处理掉在占用时间内来的人即可，反正就是模拟。
## 7-10 列车车厢重排
搞不懂为啥方案是固定的???
求序列分成最少的几组使得每组都是单减的。
[cf847B](https://codeforces.com/problemset/problem/847/B)
这个题目已经给出暴力解决方案。
```cpp
iterate through array from the left to the right;
Ivan only looks at unused numbers on current iteration;
if current number is the first unused number on this iteration or this number is greater than previous unused number on current iteration, then Ivan marks the number as used and writes it down.
```
但是cf的数据是2e5的。
题目性质是分出的几组的末尾组成的序列是不减的。 
每次二分加入值。如果太小就新开一个vector存进去。
拿到这个题上就是a[i]->n-a[i]+1.