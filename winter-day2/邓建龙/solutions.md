# day2

## 7-1

> 重点在于：
>
> 1. 重点是根据**先根序列数列**创造二叉树
> 2. 计算每层的**叶子节点的和**

```c++
// 创建二叉树
BTree createBT() {
    int data;
    BTree bt;
    scanf("%d", &data);
    if (data == 0) bt = NULL;
    else {
        bt = (BTree)malloc(sizeof(BTNode));
        bt->data = data;
        bt->lnode = createBT();
        bt->rnode = createBT();
    }
    return bt;
}
// 计算每层叶子结点和
void compute(BTree T)
{
    if (T) {
        if (T->lnode == NULL && T->rnode == NULL) {
            tot[idx] += T->data;
        }
        compute(T->lnode);
        compute(T->rnode);
        if (T->lnode != NULL && T->rnode != NULL) idx++;
    }
    return;
}
```

## 7-2

> 根据中根序列后根序列重建二叉树，易得**后根序列最后一位是根节点**
>
> 则可以递归分别求出不同子树的根节点（主要在于调整对应中根序列和后根序列的区间）
>
> 下面的代码便是，每连接一个节点，递归连接它的左右孩子

```c++
Bnode *create(int backL,int backR,int innerL,int innerR){
    if(backL>backR) {
        return NULL;
    }
    Bnode *root = new Bnode;
    root->ch = back[backR];  // A
    int i; // 2
    int flag = 0;
    for(i = innerL; i <= innerR; i++) { //1 - 3
        if (inner[i] == back[backR]) {
            flag = 1; // 正常
            break;
        }
    }
    if (flag == 1) {
        int leftN = i - innerL; // 1
        root->lchild = create(backL, backL + leftN - 1, innerL, i - 1); // 1 1 1 1
        root->rchild = create(backL + leftN, backR - 1, i + 1, innerR); // 2, 2, 3,  3
        return root;    
    } else {
        return NULL;
    }
    
}
```

## 7-4

> 并查集
>
> 在每个圈子中选出一个老大，圈子内的节点的父节点都是这个老大，没在圈子中的节点的父节点是自己
>
> **圈子合并**：将两个圈子构成的树的根节点其中一个的父节点修改成另一个根节点即可（**优化**：为了**避免树的深度过大**，可以记录每个节点作为根节点时的树的深度，将深度小的根节点的父节点修改成深度大的根节点，这样树的深度不会增加）

```c++
// 查询
int find(int x) {
    // 如果fa[x] = x 表示该节点没有父节点
    // fa[x] = find(fa[x]) 表示将该节点父节点更新为父节点的父节点
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
// 合并
void merge(int i, int j) {
    // x 表示 i 节点的父节点
    int x = find(i), y = find(j);
    // 如果 x 节点深度小于 y 节点，将 y 作为 x 节点以缩小总深度
    if (dep[x] <= dep[y]) fa[x] = y;
    else fa[y] = x;
    // 当 x == y 时，两树深度相同，合并时会深度加 1，x == y 满足, x <= y 所以 f[x] = y，即 y 节点是 x 节点父节点
    if (dep[x] == dep[y] && x != y) dep[y]++;
}
```

## 7-6

> 根据先根序列和中根序列重建二叉树，**类似 7 - 2**
>
> 递归获得节点的左右子节点即可（调整先根序列中根序列区间）
>
> **后跟遍历**：访问到一个节点时，先递归遍历它的左右子节点，再输出该节点（**第三次访问节点时输出**）

```c++
Bnode* create(int preL, int preR, int innerL, int innerR){
	if(preL > preR) return NULL;
	Bnode *root = new Bnode;
	root->data = pre[preL];
	int i;
	for(i = innerL; i <= innerR; i++) {
		if(inner[i] == pre[preL]) break;
	}
	int leftN = i - innerL;
	root->lnode = create(preL + 1,preL + leftN, innerL, i - 1);
	root->rnode = create(preL + leftN + 1, preR, i + 1, innerR);	
	return root;
}
// PostOrder
void PostOrder(Bnode* root) {
    if (root->lnode != NULL) PostOrder(root->lnode);
    if (root->rnode != NULL) PostOrder(root->rnode);
    printf("%d ", root->data);
}
```

## 7-7

> 根据先根序列和中根序列重建二叉树，然后按层遍历输出二叉树
>
> 先根据 7-6 方法重建二叉树，然后层序遍历二叉树
>
> **层序遍历**，输出一个节点后先输出它的左右子节点，再输出左右子节点的左右子节点，由这个规律可知每层先进先出（输出），所以可以使用队列
>
> **队列层序遍历**：先将根节点入队，取出队头，输出队头，然后将队头的左右子节点依次入队，直到队列为空为止，便可将二叉树层序遍历输出

```c++
// FloorOrder
void FloorOrder(Bnode* root) {
    queue<Bnode*> q;
    q.push(root);
    while (!q.empty()) {
        // 取出将要输出的节点 并把下一层也就是左右子节点入队
        Bnode* front = q.front();
        q.pop();
        // 先输出再入队左右子节点
        printf("%d ", front->data);
        if (front->lnode != NULL) q.push(front->lnode);
        if (front->rnode != NULL) q.push(front->rnode);
    }
}
```

## 7-8

> 重点在于如何将完全二叉树层序遍历数列重建成二叉树、中序遍历输出
>
> 如果按层序编号（**根节点为第 1 个节点**），第 `i` 个节点的左子节点为第 `2i` 个节点， 第 `i` 个节点的右子节点为第 `2i + 1` 个节点，递归即可
>
> **中根遍历**：访问到一个节点时，先递归遍历它的左子节点，再输出该节点，再递归遍历它的右子节点（**第二次访问节点时输出**）

```c++
// 根据完全二叉树层序遍历数列重建二叉树
Bnode* create(int idx)
{
    if (idx >= a.size() || a[idx] == 0) return NULL;
    Bnode* root = new Bnode;
    root->data = a[idx];
    root->lnode = create(idx * 2);
    root->rnode = create(idx * 2 + 1);
    return root;
}
// 中序遍历输出
// InOrder
// 是否是第一次输出
int flag = 1;
void InOrder(Bnode* root)
{
    if (root->lnode != NULL) InOrder(root->lnode);
    if (root != NULL) {
        flag == 1 ? printf("%d", root->data), flag = 0 : printf(" %d", root->data);
    }
    if (root->rnode != NULL) InOrder(root->rnode);
}
```

## 7-9

> 根据中根序列和后跟序列重建二叉树，**同 7-2**
>
> 重点是，**先跟遍历**
>
> **先跟遍历**：访问到一个节点时，先输出该节点，再递归遍历它的左右子节点（**第一次访问节点时输出**）

```c++
// PreOrder
void PreOrder(Bnode* root)
{
    printf("%d ", root->data);
    if (root->lnode != NULL) PreOrder(root->lnode);
    if (root->rnode != NULL) PreOrder(root->rnode);
}
```

