#include<iostream>

using namespace std;
int b[100] = { 0 };


typedef struct tree
{
	int data;
	struct tree* zuo, * you;
}tree, *xianjd;



xianjd setbetree() {
	int sh;
	xianjd node;
	cin >> sh;
	if (sh == 0) {
		node = NULL;
	}
	else {
		node = (xianjd)malloc(sizeof(tree));
		node->data = sh;
		node->zuo = setbetree();
		node->you = setbetree();
	}
	return node;
}

int sum = 0;
int i = 1;


void P(xianjd pd) {
	if (pd) {

		if (pd->zuo == NULL && pd->you == NULL)
			b[i] += pd->data;

		P(pd->zuo);
		P(pd->you);
		if (pd->zuo != NULL && pd->you != NULL)
			i++;
	}
	return;
}


int  compare(int* a, int k) 
{
	int i, j, temp = a[0], l = 0;
	for (j = 1; j < k; j++)
	{
		if (temp <= a[j]) 
		{
			temp = a[j];
			l = j;
		}
	}

	return l;
}





int main() {

	xianjd T = NULL;
	T = setbetree();

	if (T->zuo == NULL && T->you == NULL) 
	{ cout << "0"; return 0; }
	P(T);

	int l = compare(b, i);

	cout << l << endl;

	return 0;
}











