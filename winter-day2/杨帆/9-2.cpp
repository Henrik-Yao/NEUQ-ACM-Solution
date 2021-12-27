#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node, *BiTree;

bool judge(string a, string b) { 
    if (a.length() == 0 && b.length() == 0)
        return true;
    if (a.length() != b.length())
        return false;
    char ch = a[a.length() - 1];
    int i;
    for (i = 0; i < b.length(); i++) {
        if (ch == b[i])
            break;
    }
    string aleft = a.substr(0, i);
    string aright = a.substr(i, a.length() - 1 - i);
    string bleft = b.substr(0, i);
    string bright = b.substr(i + 1);
    for (i = 0; i < aleft.length(); i++) {
        if (bleft.find(aleft[i]) == -1)
            return false;
    }
    for (i = 0; i < aright.length(); i++) {
        if (bright.find(aright[i]) == -1)
            return false;
    }
    return judge(aleft, bleft) && judge(aright, bright);
}

BiTree create(char *post, char *in, int n) {
    if (n < 1)
        return NULL;
    BiTree tree = new Node();
    tree->data = post[n - 1];
    tree->left = tree->right = NULL;
    int i;
    for (i = 0; i < n; i++) {
        if (post[n - 1] == in[i])
            break;
    }
    tree->left = create(post, in, i);
    tree->right = create(post + i, in + i + 1, n - i - 1);
    return tree;
}

int get(BiTree tree) {
    if (!tree)
        return 0;
    int left = get(tree->left);
    int right = get(tree->right);
    return (left > right ? left : right) + 1;
}

void preorder(BiTree tree) {
    if (!tree)
        return;
    printf("%c", tree->data);
    preorder(tree->left);
    preorder(tree->right);
}

int main() {
    string a, b;
    while(cin >> a >> b){
        if (!judge(a, b))
            printf("INVALID\n");
        else {
            int n = a.length();
            char post[30], in[30];
            int p = 0;
            for (int i = 0; i < n; i++)
                post[p++] = a[i];
            p = 0;
            for (int i = 0; i < n; i++)
                in[p++] = b[i];
            BiTree tree = create(post, in, n);
            printf("%d\n", get(tree) - 1);
            preorder(tree);
            cout << endl;
        }
    }
    
    return 0;
}

