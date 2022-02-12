#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *righ;
	node(void)
	{
		left=NULL;
		righ=NULL;
	}
	~node(void)
	{
		if(left!=NULL)	delete left;
		if(righ!=NULL)	delete righ;
	}
};
