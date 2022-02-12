#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int num;
    tree *right;
    tree *left;
};
tree *create(int front[], int mid[], int len)
{
    if (!len)
        return NULL;
    int index = 0;
    int root = front[0];
    for (index = 0; mid[index] != root; index++);
    //����ѵõ�
    tree *p = new tree;
    p->num = root;
    p->left = create(front + 1, mid, index);                                //Ѱ����һ�����֧
    p->right = create(front + index + 1, mid + index + 1, len - index - 1); //Ѱ����һ���ҷ�֧
    return p;
}
// void run(tree *p)
// {
//     if(p==NULL)
//     return;
//     else
//     {
//         cout<<p->num<<endl;
//         run(p->left);
//         run(p->right);
//     }
// }
void floor_genertate(tree *head)
{
    if (head == NULL)
        cout << endl;
    queue<tree *> line;
    line.push(head);
    while (line.empty() == false) //ֻҪ���ﻹ�У��Ͳ�������
    {
        tree *remp; //��ʱ��
        remp = line.front();
        line.pop();
        cout << remp->num << " ";
        if (remp->left != NULL)
            line.push(remp->left);
        if (remp->right != NULL)
            line.push(remp->right);
    } //while ѭ���ؼ���
}
int main()
{
    int n;
    cin >> n;
    int front[100];
    int mid[100];
    for (int i = 0; i < n; i++)
        cin >> front[i];
    for (int i = 0; i < n; i++)
        cin >> mid[i];
    tree *head = new tree;
    head = create(front, mid, n);
    // run(head);
    floor_genertate(head);
    return 0;
}