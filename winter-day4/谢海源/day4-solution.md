# day4-solution

## **7-1 双十一**

用Floyd寻找每个点作为起点时到其余每个点的最短路径，求出到其余点总距离和最短的那个点作为建立仓库的点

## **7-2 路由器**

用Floyd求最短路径，默认每个直接连接的路由器之间的距离为1，递归存路径的path数组求深度，即最短路径的“跳数”

## **7-3 最短路径之Dijkstra**

用dijkstra求最短路径，用递归实现打印路径，注意起始点与终点相同时的打印

## **7-4 最短路径之Floyd**

用Floyd求最短路径，path数组存i到j之间通过的点k，通过path数组递归打印路径

## **7-5 迷宫变种-最短路径**

用bfs访问所有点后存起始点到其余点所需的最小耗费能量，打印时从终点开始，向所需能量小的地方寻找路径打印即可

## **7-6 森森旅游**

(https://blog.csdn.net/liuchuo/article/details/118843047)