# day2题解

### **7-1 二叉树叶结点值和最大层**

根据先序遍历将树建立起来，并记录每个节点的深度。取值操作要注意是叶子节点，即左子树和右子树都为空。要记录一下每一层的个数，因为值可能是负数，所以需要判断该层是否有叶子节点。

### 

### **7-2 重建二叉树**

先根据中序和后序建树，根的高度=max（左子树的高度，右子树的高度）+1，可以进行递归实现。删除操作即将所有的都赋值为NULL即可。判断是否合法只需判断子树的值对应相同并且长度相同即可。

### 

### **7-4 罪犯帮派**

并查集的典型例题，记住模板

### **7-6 先序和中序构造二叉树**

反向建树的方式还是渗透了分治法的思想，通过分治把一个序列不断分支成左右子树，知道分治到叶结点。因此我们可以总结出建树的算法思路

### **7-7 按层遍历二叉树**

首先通过先序和中序遍历将树建立，然后用队列实现按层遍历，如果队首存在左右子树，就将他们入队，然后队首出队即可。

### **7-9 后序和中序构造二叉树**

后序和中序遍历的左子树都是在开头，然后右子树就差一个根的位置，根据这个性质可以分治建树。