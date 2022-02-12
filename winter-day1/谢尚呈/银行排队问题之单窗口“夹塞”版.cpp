#include<iostream>
#include<string>
#include<cstdio>
using namespace std;//��һ�������¼�°���ҵ��Ĵ���,��ID��Ͱ����ÿ���˵�����Ȧ
struct rou;	//����Ȧ�ṹ 
struct peo;	//һ���˽ṹ
struct lis;	//��������ṹ 

int get_id(string name)//ͨ��������д��ĸ��ȡid�Ĳ��� 
{
	int it=0;
	for(int i=0; i<3; i++)
	{
		it*=100;
		it+=name[i]-'A';
	}
	return it;
}

peo* index_node[1000000];//����ID�������˽ڵ��ַ��ֱ�Ӳ��� 
int index_frie[1000000];//����ID��������Ȧ��� 

struct rou{	//����Ȧ�ṹ 
	//int ids[100];	//���Ȧ����ÿ���˵�id������û��Ҫ 
	int last;		//���Ȧ������������˵�id 
	rou(void)
	{
		last=0;
		return;
	}
}round[101];		//����Ȧ�������0��ζ���ǹ¶���0������Ȧ������ 

struct peo{	//�����˽ṹ 
	int id;			//����ID 
	string name;	//����
	int arrive;		//����ʱ��
	int waitin;		//�ȴ������ʱ����Կ�ʼ 
	int useing;		//ռ��ʱ��������Ϊusing���ؼ����ˣ����Ǵ��
	peo *pre, *nex;	//ǰ������� 
	peo(void)
	{
		pre=NULL;
		nex=NULL;
		arrive=0;
		waitin=0;
		useing=0;
	}
};

struct lis{	//�������
	peo *head, *tail, *self;
	
	lis(void)
	{
		head=new peo;
		tail=new peo;
		head->nex=tail;
		tail->pre=head;
		return;
	} 
	
	void add(peo *it)//��һ���ڵ������ĩλ 
	{
		it->nex=tail;
		it->pre=tail->pre;
		it->nex->pre=it;
		it->pre->nex=it;
		it->waitin=it->pre->waitin+it->pre->useing;
		if(it->waitin<it->arrive)	it->waitin=it->arrive;
		return;
	}
	void insert(peo *area, peo *it)//��it����area֮��
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
		if(num_fri==0)	//û������
			add(self);
		else if((round[num_fri].last==0)||
			((index_node[round[num_fri].last]->waitin+index_node[round[num_fri].last]->useing)<self->arrive))
		{
			//�����ѣ����ǲ��ܼ���
			add(self);
			round[num_fri].last=self->id; 
		}
		else	//���������ܼ��� 
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
	int n, m;	//������������Ȧ����
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
