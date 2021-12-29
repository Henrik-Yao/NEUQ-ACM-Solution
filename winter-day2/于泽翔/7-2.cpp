#include <bits/stdc++.h>
using namespace std;
string post, mid;
int l_p, l_m, ft;

struct tnode{
	char data;
	int level;
	tnode* left;
	tnode* right;
};

void newtree(tnode*& t, int len, int p, int in)
{
    int pos = 0, f=0;
   
    int inend = in + len;
    int pend = p + len;

    for (pos = in; pos < inend; pos++)
        if (mid[pos] == post[pend - 1]) {
            f= 1;
            break;
        }
   
    int leftlen = pos - in;
    int rightlen = len - pos - 1 + in;
    if (f)
	{
        t = new tnode;
        t->data = mid[pos];
        if (leftlen > 0)
            newtree(t->left, leftlen, p, in);
        if (rightlen > 0)
            newtree(t->right, rightlen, p + pos - in, pos + 1);
    }
    else
       ft= 0;
}
void putt(tnode* t)
{
	if(t==NULL)
		return;
	cout<<t->data;
	putt(t->left);
	putt(t->right);
}
int height(tnode* t)
{
	if(t==NULL)
		return -1;
	int l_h=height(t->left), r_h=height(t->right);
	return max(l_h+1, r_h+1);
}
int main(void)
{
	while(getline(cin, post))
	{
		getline(cin, mid);
		l_p=post.size();
		l_m=mid.size();
		ft=1;
		
		tnode* root=new tnode;
		newtree(root, l_p, 0, 0);
		
		if(ft)
		{
			cout<<height(root)<<endl;
			putt(root);
            cout<<endl;
		}
		else
			cout<<"INVALID"<<endl;
	}
	return 0;
}