### 7-1：

简单DP，话不多说：

$f[i]=max\{f[i-1]+a_i,0\}$



### 7-2：

Week2原题，先将$n-1$个盘移动到中间，再将第$n$个盘移到右边，再把$n-1$个移回去。



### 7-3：

先把$n-1$个盘移到最右边，然后把$n$号盘移到中间，再把$n-1$个移到最左边，再把$n$号盘移到最右边，最后把 $n-1$个盘移回来。故：$f[i]=3f[i-1]+2$



### 7-4：

肯定是先将$n-1$个盘移动到另外两根柱子上，枚举$a$个盘移动到了第$2$根，$n-1-a$个移动到了第$4$根，然后就转化为了一个$4$柱和一个$3$柱的子问题。$f[i]=\max_{1≤a≤n-1}\{2(f[a]+g[n-1-a])+1\}$，其中$g[n]$表示$3柱n盘$时的解。



### 7-5：

就是排个序，怎么排都行，Sort就完了。



### 7-6 :

全排列，枚举第一个位置放哪些，然后后面接另外$n-1$个字符的全排列即可（递归），注意去重然后排序。

也可以直接next_permutation();



### 7-7：

在归并排序的时候统计，因为归并排序合并时右边的下标一定大于左边，然后左右两边的数都是有序的，在合并的时候算一下就好。注意处理相等的数。

实际这样很不好写，不如直接离散化后树状数组。

注意到逆序对的本质是二维偏序，还可以使用二维线段树，KD-Tree，CDQ分治，分块+Bitset等方法。



### 7-8：

没啥好说的，lower_bound或者手写二分都行。
