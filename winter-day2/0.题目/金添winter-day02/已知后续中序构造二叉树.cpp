#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int num;
    tree *left;
    tree *right;
};
void fro_create(int mid[], int post[], int len)
{
    if (!len)
        return;
    int index = len - 1;
    int root = post[len - 1]; //���ڵ�
    for (index = len - 1; root != mid[index]; index--);
    //��ȡ����ڵ���±�
    cout << root << " ";
    fro_create(mid, post, index);
    fro_create(mid + index + 1, post + index, len - index - 1); // ע���˴�post�����ַ�����1��
}
int main()
{
    int len;
    cin >> len;
    int mid[100];
    int post[100];
    for (int i = 0; i < len; i++)
        cin >> post[i];
    for (int i = 0; i < len; i++)
        cin >> mid[i];
    fro_create(mid, post, len);
    return 0;
}