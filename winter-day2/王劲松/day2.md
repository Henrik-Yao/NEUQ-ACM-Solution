# 7-1 二叉树叶结点值和最大层

已知一棵非空二叉树结点的数据域为不等于0的整数，请编写程序找出该二叉树中叶结点数据值之和最大的层。

根据先序根左右的特点读数据建树，然后求每层和

------

# 7-2 重建二叉树

给定非空二叉树的中根序列和后根序列，请编写程序创建该二叉树，计算其高度和先根序列，最后删除该二叉树；如给定的中根和后根序列不合法，则亦能识别。

### 输入格式:

输入包含多组数据（不超过10组），每组为两行字符串，第一行表示某二叉树的后根序列，第二行表示其中根序列。结点的值均为A-Z的大写字母，故二叉树结点个数不超过26，且保证输入的两个序列都是结点的全排列，但不一定是合法的中根和后根序列。输入保证不是空二叉树。

在后序中相对最后的是根，然后再中序中分左右建树，然后判断该树的中序和后序是不是输入的中序和后序

------

# 7-6 先序和中序构造二叉树

本题目要求用先序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其后序序列。

先序中相对最前的是根，然后在中序中分左右建树

------

# 7-7 按层遍历二叉树

用先序和中序序列构造一棵二叉树（树中结点个数不超过10个），通过用队记录结点访问次序的方法实现对二叉树进行按层遍历，即按层数由小到大、同层由左到右输出按层遍历序列。

建树，然后用queue放入根，当！queue.empty(),放入其左右分支

------

# 7-8 中序遍历二叉树

按完全二叉树的层次遍历给出一棵二叉树的遍历序列（其中用0表示虚结点），要求输出该二叉树的深度及中序遍历该二叉树得到的序列。

用数组存输入数据，以a[1]为根,左分支为a[i+i]，右分支为a[i+i+1].

------

# 7-9 后序和中序构造二叉树

本题目要求用后序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其先序序列。

同7-2