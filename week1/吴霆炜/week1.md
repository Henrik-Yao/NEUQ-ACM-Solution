# Week1.题解 #


## 1.string ##

将文本串定义为一个字符数组，再定义两个字符串，一个用于存储输入的模式串，另一个用于与截取文本串，再将截取文本串的字符串与模式串对比。若相等，则算出现一次，以此类推。

## 2.区间 ##
开两个数组，一个存前半段权值出现的次数，一个存后半段权值出现的次数。再定义三个变量，分别储存答案，前半段权值和后半段权值。再枚举两端区间的分界点（初始时为1），同时，每次变动前半段多分界点上的数，后半段少分界点上的数，再将每次的值求最大值即可。

## 3.小步点 ##
画图+推测可知，应先到（d,n - R），再到(2d,0)，再减去R即为最短距离。
注意：1.n,d可能为负数；
2.当n<=R时，可直接从x轴过去得到最小值，即2d-R。

## 4.分糖果 ##
知识点：递归
只剩一颗糖时，返回1。
否则，找约数，再对约数递归。
注意：不分也是一种情况。

## 5.找眼镜 ##
定义结构体储存每个人的朝向和姓名，再定义pos指针（初始指向第一个人），再通过人的朝向和提示发现两者相等时为顺时针，不等时为逆时针。

## 6.恰早饭 ##
两种情况：1.t>T，使用题中所给公式，再相加；
2.t<=T,直接相加即可。
将两种情况的和都存入一个数组，再求数组的最大值即可。