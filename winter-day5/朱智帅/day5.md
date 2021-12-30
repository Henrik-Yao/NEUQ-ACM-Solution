# 7-1

sort后对每一个数进行逐步判断。

# 7-2

不会，我麻了

# 7-3

sort后按要求输出

# 7-4

二分法，用mid与目标结果进行比较，在没有找到的情况下如果大的话就修改right否则修改left。

# 7-5

不知道为啥我的代码只能过样例，这是链接：

https://blog.csdn.net/SYaoJun/article/details/102151070?spm=1001.2101.3001.6650.12&utm_medium=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~default-12.queryctr&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~BlogCommendFromBaidu~default-12.queryctr&utm_relevant_index=14

在这里解释一下思想：运用map，以string为下标记录该名字的人的父亲和性别。之后运用二重循环来解决来寻找是否在五代以内。

# 7-6

同7-3

# 7-7

设定合理的距离为最终查找目标，通过juidge进行判断，right为最大距离，left为1，通过二分的思想进行查找，最终选的最大的合理距离。