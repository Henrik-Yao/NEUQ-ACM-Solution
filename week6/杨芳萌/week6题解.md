## KMP

一道kmp的板子题





## 妈妈再也不用担心我

熟悉一下map的用法，用map就随便过了

> map<string,string> node;
>
> 注册：node[name] =  password;
>
> 查重：node[name] != "";
>
> 判断：node[name] == password;

这题与其说是字符串哈希不如说是个模拟题



## 字符串个数匹配

首先要处理一下字符串分块，把这个长字符串拆开

然后让我来试一下stl里的string.find()能不能水过这个题

水过了！

> for(int i=0; i<=cnt; i++) 
>
> ​	if(c[i].find(b)!=-1) 	
>
> ​		ans++;

嘻嘻