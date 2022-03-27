# 最少失约数

主要是贪心算法，先按结束时间进行升序排序，记录当前时间结束时间(nowend)，然后从头开始遍历(nowend=0为初值),当当前节点的开始时间大于nowend时，cnt++，nowend更新。

# 跳一跳

主要也是贪心算法,记录nowmax和nextmax，nowmax=1和nextmax=maxstep[1]+1为初值，遍历每一个节点若当前节点大于nowmax，cnt++，nowmax=nextmax，同时每一个节点计算i+maxstep[i],若大于nextmax则更新。