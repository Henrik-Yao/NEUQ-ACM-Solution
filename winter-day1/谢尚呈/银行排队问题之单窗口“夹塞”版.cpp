#include<iostream>
#include<string>
#include<cstdio>
using namespace std;//用一个链表记录下办理业务的次序,用ID来桶索引每个人的朋友圈
struct rou;	//朋友圈结构 
struct peo;	//一个人结构
struct lis;	//队列链表结构 

int get_id(string name)//通过三个大写字母获取id的操作 
{
	int it=0;
	for(int i=0; i<3; i++)
	{
		it*=100;
		it+=name[i]-'A';
	}
	return it;
}

peo* index_node[1000000];//依据ID索引个人节点地址，直接插入 
int index_frie[1000000];//依据ID索引朋友圈编号 

struct rou{	//朋友圈结构 
	//int ids[100];	//这个圈子内每个人的id，发觉没必要 
	int last;		//这个圈子最后来到的人的id 
	rou(void)
	{
		last=0;
		return;
	}
}round[101];		//朋友圈索引编号0意味着是孤儿，0号朋友圈不启用 

struct peo{	//单个人结构 
	int id;			//个人ID 
	string name;	//名字
	int arrive;		//到达时间
	int waitin;		//等待到这个时间可以开始 
	int useing;		//占用时长，是因为using作关键字了，不是打错
	peo *pre, *nex;	//前驱，后继 
	peo(void)
	{
		pre=NULL;
		nex=NULL;
		arrive=0;
		waitin=0;
		useing=0;
	}
};

struct lis{	//链表队列
	peo *head, *tail, *self;
	
	lis(void)
	{
		head=new peo;
		tail=new peo;
		head->nex=tail;
		tail->pre=head;
		return;
	} 
	
	void add(peo *it)//将一个节点插入在末位 
	{
		it->nex=tail;
		it->pre=tail->pre;
		it->nex->pre=it;
		it->pre->nex=it;
		it->waitin=it->pre->waitin+it->pre->useing;
		if(it->waitin<it->arrive)	it->waitin=it->arrive;
		return;
	}
	void insert(peo *area, peo *it)//将it插入area之后
	{
		it->pre=area;
		it->nex=area->nex;
		it->pre->nex=it;
		it->nex->pre=it;
		it->waitin=it->pre->waitin+it->pre->useing;
		peo *oper=it->nex;
		while(oper!=tail)
		{
			oper->waitin+=it->useing;
			oper=oper->nex;
		}
		return;
	} 
	
	peo *arri(string name, int arrive, int useing)
	{
		self=new peo;
		self->name=name;
		self->arrive=arrive;
		self->useing=useing;
		self->id=get_id(self->name);
		index_node[self->id]=self;
		
		int num_fri=index_frie[self->id];
		if(num_fri==0)	//没有朋友
			add(self);
		else if((round[num_fri].last==0)||
			((index_node[round[num_fri].last]->waitin+index_node[round[num_fri].last]->useing)<self->arrive))
		{
			//有朋友，但是不能加入
			add(self);
			round[num_fri].last=self->id; 
		}
		else	//有朋友且能加入 
		{
			insert(index_node[round[num_fri].last], self);
			round[num_fri].last=self->id;
		}
		
		return self;
	}
	
	double count(void)
	{
		double cou=0;
		self=head->nex;
		while(self!=tail)
		{
			if(self->waitin>=self->arrive)
				cou+=self->waitin-self->arrive;
			self=self->nex;
		}
		return cou;
	}
	void write(void)
	{
		self=head->nex;
		while(self!=tail)
		{
			cout<<self->name<<endl;
			self=self->nex;
		}
		return;
	}
	
	~lis(void)
	{
		self=head;
		while(self->nex!=tail)
		{
			peo *it=self->nex;
			self->nex=self->nex->nex;
			delete it;
		}
		delete head;
		delete tail;
	}
};

int main()
{
	int n, m;	//总人数，朋友圈个数
	lis all;
	cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int tot;
		cin>>tot;
		for(int j=0; j<tot; j++)
		{
			string name;
			cin>>name;
			index_frie[get_id(name)]=i;
		}
	}
	for(int i=0; i<n; i++)
	{
		string name;
		int arrive, useing;
		cin>>name>>arrive>>useing;
		if(useing>60)	useing=60;
		all.arri(name, arrive, useing);
	}
	double count=all.count();
	all.write();
	printf("%.1lf", count/double(n));
	return 0;
}
