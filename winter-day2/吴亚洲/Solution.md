# Solution

**7-1 二叉树叶结点值和最大层**

以ans[i]记录第i层所有符合条件的节点数据之和，首先按照给出的先根序列建立二叉树并记录每个节点的层数，然后遍历整棵树，找到符合条件的节点后，当前层ans[i]加上该节点的值，遍历完成后找到ans[i]的最大值输出即可。

**7-2 重建二叉树**

后跟序列中某一段的最后一个节点为整段构成的树的根，在中根序列中找到这一点，则其左边的节点代表所有在根节点左边的点，右边的所有点代表所有在根节点右边的点，找完一段之后依次再找左边和右边的一段，利用递归完成该过程。

**7-4 罪犯帮派**

并查集的应用。对于两个给定的在同一帮派的人，将他们归到同一棵树中，即对应相同根节点，之后在每次查找时只需判断两节点的根是否相同即可。

**7-6 先序和中序构造二叉树**

先跟序列中某一段的第一个节点为整段构成的树的根，在中根序列中找到这一点，则其左边的节点代表所有在根节点左边的点，右边的所有点代表所有在根节点右边的点，找完一段之后依次再找左边和右边的一段，利用递归完成该过程。

**7-7 按层遍历二叉树**

先通过先序和中序序列构造一棵树，然后建立队列解题：先将根节点放入队列，之后只要队列不为空，依次执行：放入头元素的左节点》》放入头元素的右节点》》头元素出队并输出。

**7-8 中序遍历二叉树**

先根据给出的层次遍历序列造树，之后进行中序遍历，同时记录深度，输出结果即可。

**7-9 后序和中序构造二叉树**

同7-2。