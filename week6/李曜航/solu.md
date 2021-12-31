## 7-1

KMP板子题目

## 7-2

很友好无坑点的题

按题意求得hash

这里用了一个map来获取对应user的password和hash值

map的使用上，我之前判断是不是存过这个人用的是map.find()!=map.end()，但是没有存入第一个数据的时候就会出问题，换用了map.count()

## 7-3

处理一下输入的KMP