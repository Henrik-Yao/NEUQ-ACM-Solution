#include <bits/stdc++.h>
using namespace std;
void post_create(int preorder[], int inorder[], int len)
{
    if (len == 0)
        return;
    int index=0;//一个定位光标
    int root=preorder[0];
    for(index=0;root!=inorder[index];index++);
    //空循环，目的是找到根节点在中序的下标    
    post_create(preorder+1,inorder,index);
    post_create(preorder+index+1,inorder+index+1,len-index-1);
    cout<<*preorder<<" "; //因其为后续输出，需要将其放置最后进行输出。
}
int main()
{
    int n;
    int fro_get[1000];
    int mid_get[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> fro_get[i]; //前序获得
    for (int i = 0; i < n; i++)
        cin >> mid_get[i]; //中序获得
    post_create(fro_get, mid_get, n);

    return 0;
}