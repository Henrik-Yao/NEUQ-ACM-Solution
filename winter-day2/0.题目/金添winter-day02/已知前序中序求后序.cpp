#include <bits/stdc++.h>
using namespace std;
void post_create(int preorder[], int inorder[], int len)
{
    if (len == 0)
        return;
    int index=0;//һ����λ���
    int root=preorder[0];
    for(index=0;root!=inorder[index];index++);
    //��ѭ����Ŀ�����ҵ����ڵ���������±�    
    post_create(preorder+1,inorder,index);
    post_create(preorder+index+1,inorder+index+1,len-index-1);
    cout<<*preorder<<" "; //����Ϊ�����������Ҫ������������������
}
int main()
{
    int n;
    int fro_get[1000];
    int mid_get[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> fro_get[i]; //ǰ����
    for (int i = 0; i < n; i++)
        cin >> mid_get[i]; //������
    post_create(fro_get, mid_get, n);

    return 0;
}