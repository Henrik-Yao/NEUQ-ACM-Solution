# 7-1

Floyd算法；

# 7-2

Floyd算法;

# 7-3

Floyd算法；

# 7-4

Floyd算法；

# 7-5

我运用了搜索的算法，主要方法有两种：

1、运用等待的办法来处理时间花费不是1的点，具体来说就是在visit一个点时若它的cost大于一，将其cost--后重新加入列表中，当一个点被访问时用visit记录，避免重复访问。（BFS）

2、运用visit记录到达该节点的最小花费，若到达该节点时，花费多于visit记录值则返回。（DFS）

关于路径的存储路径；

运用vector，将结构体中加入一个记录坐标的vector变量，在额外定义一个MinWay的变量，用来存储最后最短的路径。

关于剪枝：

1、记录已经找到的最小值，若记录的最小值小于当前值，则直接返回。

# 7-6

不会，这是链接。

https://blog.csdn.net/zstuyyyyccccbbbb/article/details/116107268?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164069040916780366582015%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164069040916780366582015&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-116107268.pc_search_insert_es_download_v2&utm_term=7-6+%E6%A3%AE%E6%A3%AE%E6%97%85%E6%B8%B8&spm=1018.2226.3001.4187