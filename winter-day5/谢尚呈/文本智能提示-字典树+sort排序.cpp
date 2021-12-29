#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;		//字典数，查询数，输出结果数 

struct node{
	long long pow;	//如果这个能作为结束节点，这个单词的频次 
	node *tow[36]; 	//指向下一个节点，0~9，a~z
	char mts;		//这个节点的字符值 
	node(void)
	{
		pow=-1;
		for(int i=0; i<36; i++)	tow[i]=NULL;
	} 
};

struct resu{
	string self;
	long long pow;
	friend bool operator < (resu x, resu y)
	{
		return x.pow>y.pow;
	}
};
typedef resu my_set;

int max_m=0;	//在数组中最大下标 

int map_str(char it)
{
	if(it>='0'&&it<='9')	return it-'0';
	else	return it-'a'+10;
}

void search(string has, node *self, my_set *libr)
{
	string ths=has;
	ths+=self->mts;
	if(self->pow>=0)
	{
		resu it;
		it.self=ths;
		it.pow=self->pow;
		libr[max_m]=it;
		max_m+=1;
	}
	for(int i=0; i<36; i++)
	if(self->tow[i]!=NULL)	search(ths, self->tow[i], libr);
	return;
}

void call(string org, node *root)
{
	my_set libr[10001];
	max_m=0;
	for(int i=0; org[i]!='\0'; i++)
	if(root->tow[map_str(org[i])]==NULL)
	{
		cout<<"no suggestion"<<endl;
		return;
	}
	else root=root->tow[map_str(org[i])];
	for(int i=0; i<36; i++)
	if(root->tow[i]!=NULL)	search(org, root->tow[i], libr);
	int out=0;
	sort(libr, libr+max_m);
	for(int i=0; i<max_m; i++)
	{
		cout<<libr[i].self<<endl;
		out++;
		if(out==k)	break;
	}
	return;
}

void add(string it, long long pow, node *root)
{
	for(int i=0; it[i]!='\0'; i++)
	{
		int maps=map_str(it[i]);
		if(root->tow[maps]==NULL)
		{
			node *oper=new node;
			oper->mts=it[i];
			root->tow[maps]=oper;
		}
		root=root->tow[maps];
	}
	if(root->pow>pow);
	else	root->pow=pow;
	return;
}

int main()
{
	cin>>n>>m>>k;
	node *root=new node;
	for(int i=0; i<n; i++)
	{
		string it;
		long long pow;
		cin>>pow>>it;
		add(it, pow, root);
	}
	for(int i=0; i<m; i++)
	{
		string it;
		cin>>it;
		call(it, root);
		if(i!=m-1)	cout<<endl;
	}
	return 0;
}
