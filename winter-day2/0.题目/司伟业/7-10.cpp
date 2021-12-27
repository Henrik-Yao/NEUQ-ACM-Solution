#include <stdio.h>
#include <string.h>
#include <iostream>
#define maxn 1010
using namespace std;
 
int pre[maxn], in[maxn], post[maxn];
int n;
int cnt;
 
int ask_root(int len, int root, int in[]) {
    for (int i=0; i<len; ++i) {
        if (in[i] == root)
            return i;
    }
    return -1;
}
 
void askPre(int len, int in[], int post[]) {
    int root_id = ask_root(len, post[len-1], in);
    if (root_id == -1) return;
    pre[cnt++] = post[len-1]; // 将当前根节点加入到先序序列中
    askPre(root_id, in, post); // 递归到左子树
    askPre(len-root_id-1, in+root_id+1, post+root_id); //递归到右子树
}
 
 
int main() {
	cin>>n;
    cnt = 0;
    for (int i=0; i<n; ++i) cin >> post[i]; 
    for (int i=0; i<n; ++i) cin >> in[i];
    askPre(n, in, post);
    for (int i=0; i<n; ++i)
    cout << pre[i] <<" ";
    return 0;
}
