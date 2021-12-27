#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Node {
    //值 
    char data;
    //该点概率 
    int weight;
    //左孩子 右孩子 父母 
    int lchild, rchild, parent;
    //当前的层次 
    int length;
};
//这个flag函数是验证最终得到的哈夫曼树和给出的编码的最短带全长度是否相同
//同时判断给出的哈夫曼编码是否符合唯一性 
int flag(Node H_Tree[100], int short_way, int n) {
    char coding[100][100];
    char c[100];
    for (int i = 0; i < n; i++) {
        cin>>c[i];
        cin>>coding[i];
    }
    //对于给出的哈夫曼编码计算带权路径长度 
    int short_way1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (H_Tree[i].data == c[j]) {
                short_way1 += H_Tree[i].weight * strlen(coding[j]);
                break;
            }
    }
    //判断这两个带权路径长度是否相同 
    if (short_way1 != short_way)
        return 0;
    //下判断是否含有前缀重叠
    int vist[1000] = { 0 };
    int min;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vist[j]) {
                min = j;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (strlen(coding[j]) < strlen(coding[min]) && !vist[j])
                min = j;
        }
        vist[min] = 1;
        for (int j = 0; j < n; j++) {
            if (!strncmp(coding[min], coding[j], strlen(coding[min])) && !vist[j])
                return 0;
        }
    }
    return 1;
}
int main() {
    //先建立一堆节点 
    Node H_Tree[1000];
    int n;
    //输入节点个数 
    scanf("%d", &n);
    //初始化节点的信息，一开始由于还无法建立哈夫曼树，所以父母为-1，孩子为-1 
    for (int i = 0; i < n; i++) {
        cin >> H_Tree[i].data;
        cin >> H_Tree[i].weight;
        H_Tree[i].parent = -1;
        H_Tree[i].lchild = -1;
        H_Tree[i].rchild = -1;
    }
    int i;
    for (i = 0; i < n - 1; i++) {
        //挨个遍历，找到两个概率最小的节点 
        int j;
        for (j = 0; j < n + i; j++) {
            if (H_Tree[j].parent == -1)
                break;
        }
        int min1 = j;
        for (int k = 0; k < n + i; k++) {
            if (H_Tree[min1].weight > H_Tree[k].weight && H_Tree[k].parent == -1)
                min1 = k;
        }
        //更新节点的父母为当前数组个数后面的一个值
        //也就是说数组前面存储每个叶子节点，后面存储两个节点合并后的节点 
        H_Tree[min1].parent = n + i;
        for (j = 0; j < n + i; j++) {
            if (H_Tree[j].parent == -1)
                break;
        }
        int min2 = j;
        for (int k = 0; k < n + i; k++) {
            if (H_Tree[min2].weight > H_Tree[k].weight && H_Tree[k].parent == -1)
                min2 = k;
        }
        H_Tree[min2].parent = n + i;
        //将合并后的节点的信息进行更改 
        H_Tree[n + i].weight = H_Tree[min1].weight + H_Tree[min2].weight;
        H_Tree[n + i].parent = -1;
        H_Tree[n + i].lchild = min1;
        H_Tree[n + i].rchild = min2;
    }
    //初始化最短长度 
    int short_way = 0;
    for (i = 0; i < n; i++) {
        //挨个遍历更新最短长度 
        H_Tree[i].length = 0;
        int temp = i;
        while (H_Tree[temp].parent != -1) {
            H_Tree[i].length++;
            temp = H_Tree[temp].parent;
        }
        short_way += H_Tree[i].weight * H_Tree[i].length;
    }
    int count;
    scanf("%d", &count);
    int flag1[10000];
    //利用flag函数对于所有的哈夫曼编码例子进行校验 
    for (int k = 0; k < count; k++) {
        flag1[k] = flag(H_Tree, short_way, n);
    }
    //输出结果 
    for (int k = 0; k < count; k++) {
        if (flag1[k])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

