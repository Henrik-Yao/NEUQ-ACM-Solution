# 7-1

运用递归思想

n个盘子从a到c，想当于：

**1.** n-1个盘子到b

**2.**一个盘子到c

**3.**再n-1个盘子到c

由此可以通过把n个盘子逐个简化成1个盘子的移动，最后再合并答案

# 7-2

**我比较笨**

我记录每个城市连接了几个城市，并且用**链式前向星**存储这m条边，

当一个城市被消灭时，它自己连接的城市改为0，用链式前向星遍历与该城市连接的城市，每个它所连接的城市的连接城市数减1

到最后遍历一遍每个城市的连接城市数，如果有的城市连接城市数大于等于1，则说明该方案不行

**正解**

不用链式前向星，其实该题只需要再操作后**遍历输入时的m条边，**并判断每条边所连接的两座城市的连接城市数是否大于等于1即可

# 7-3

大家都知道该用啥去打，（doge），对吧，sort？