**7-1 二叉树叶结点值和最大层**

参考[7-1 二叉树叶结点值和最大层 (10 分)_今天还剩几根头发的博客-CSDN博客](https://blog.csdn.net/weixin_49527015/article/details/118083441)

**7-2 重建二叉树**

跟中二叉树中序和后续遍历的特点进行操作

**7-3 树最近公共祖先**

左右子树递归，参考[（二叉树）二叉树的最近公共祖先_HerofH_的博客-CSDN博客_二叉树最近公共祖先](https://blog.csdn.net/qq_28114615/article/details/85715017)

​		如果从根节点开始，递归左右子树，寻找目标值

​		临界条件：如果没有子树了，或者本身就是目标是，返回当前位置即可。如果左子树返回有效值，右子树为NULL，则返回左子树的返回值；右子树同理。如果左右同时返回有效值，则当前位置即为答案，返回当前值。

```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p||root==q||!root)return root;
        
        TreeNode* left=lowestCommonAncestor(root->left,  p, q);
        TreeNode* right=lowestCommonAncestor(root->right,  p, q);
        
        if(!left&&!right)return NULL;
        else if(left&&!right)return left;
        else if(right&&!left)return right;
        
        return root;
    }
```

**7-4 罪犯帮派**

用的vector+map，注意单独一个人也算一个帮派

**7-5 哈夫曼编码**

首先判断构成哈夫曼树的WPL（树的带权路径的长度，叶节点）。

WPL用小根堆，每次取最小的两个组成一颗树，再放入堆中，新树的权值为两个小树权值之和。

如果目标编码的WPL值与哈夫曼树的WPL值不同，则No；

如果相同再判断是否为前缀码即可。

参考 [PTA哈夫曼编码 (30分)_yan936462437的博客-CSDN博客_pta哈夫曼编码](https://blog.csdn.net/yan936462437/article/details/104209299)

**7-6 先序和中序构造二叉树**

**7-7 按层遍历二叉树**	

**-8 中序遍历二叉树**

**7-9 后序和中序构造二叉树**

同类题目，树的遍历与构造

