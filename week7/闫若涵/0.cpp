#include<bits/stdc++.h>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define M 3//定义阶数
#define Super_Manager_Code 1000  //超级管理员密码
#define MAX_NAME_LEN 20//姓名长度
#define MAX_BKNAME_LEN 50
#define OK 1
#define ERROR 0
#define	bookinfomationfile "bookinfo.txt"	// 图书信息文件
#define	borrowerfile "borrower.dat"		// 借阅者名单文件
typedef int KeyType;
typedef int Status;

/*****************************书和借阅者结点存储定义*************************/
typedef struct ReaderNode {//借阅者
	int IDnum;                      //ID号
	char reader_name[MAX_NAME_LEN]; //姓名
	ReaderNode *rnext;              //指向下一个借阅者的指针
}ReaderNode, *ReaderType;

typedef struct BookNode {
	int booknum;   //书号
	char bookname[MAX_BKNAME_LEN];  //书名
	char writer[MAX_NAME_LEN];      //作者名字
	int current;                    //现存量
	int total;						//总库存
	int published_year;				//出版年份
	float price;					//价格
	ReaderType reader;				//借阅者链表指针
}BookNode, *BookType;				//图书类型

typedef BookNode Record;			//将书的结点定义为记录

/*******************************B树存储定义***************************/

typedef struct BTNode {        //B树结点类型定义
	int keynum;			       //结点中关键字个数，即结点的大小
	KeyType key[M+1];		   //关键字，key[0]未用
	struct BTNode *parent;	   //双亲结点指针
	struct BTNode *ptr[M + 1]; //孩子结点指针数组
	Record *recptr[M + 1];     //记录指针向量，0号单元未用
}BTNode, *BTree;			   //B树结点和B树类型

typedef struct result {
	BTNode *pt;				  //指向找到的结点
	int i;					  //1<=i<=m,在结点中的关键字位序
	int tag;				  //1:查找成功，0:查找失败
}result, *resultPtr;		  //B树的查找结果类型



 /*******************************B树接口定义***************************/


result SearchBTree(BTree T, int k);
/*
	初始条件:树T存在
	操作结果:在m阶B数T上查找关键字k，返回p{pt,i,tag}
*/

Status InsertBTree(BTree &T, int k, BTree q, int i, Record *recptr);
/*
	初始条件:树T存在
	操作结果:在B树T上结点p->pt的key[i]和key[i+1]之间插入关键字k
*/

Status DeleteBTree(BTree &T, int k);
/*
	初始条件:B树上p结点存在
	操作结果:删除B树T上结点p->pt的关键字k
*/

void BTreeTraverse(BTree T, void(*visit)(BTree));
/*
	初始条件:树T存在
	操作结果:遍历B树
*/


int menu();
/*
	输出选择菜单
*/

void ShowBTree(BTree T, short x = 8);
/*
	以凹入表的形式输出B树
*/
int login();
/*
	登陆界面
*/

/*******************************图书馆接口定义***************************/
void InitLibrary(BTree &L);
/*
	初始化一棵空树
*/
void InsertBook(BTree &L, BookType B, result res);
/*
	插入新的书籍
*/
int DeleteBook(BTree &L, BookType B);
/*
	删除已存在的书籍，不存在则提示不存在
*/
int CanBorrow(BTree L, BookType B, ReaderType R);
/*
	判断指定书籍能否出借
*/
void BorrowBook(BTree L, BookType B, ReaderType R);
/*
	书籍出借
*/
int ReturnBook(BTree L, int booknum, int IDnum, BookType &B, ReaderType &R);
/*
	书籍归还
*/
void PrintH();
/*
	输出表格的头部
*/
void PrintB(BookType B);
/*
	输出指定书籍的信息
*/
void PrintT();
/*
	输出表格的尾部
*/
void PrintAll(BTree p);
/*
	输出B树结点的全部关键字信息
*/
void PrintBook(BookType B);
/*
	以表格形式输出一本书的信息
*/
void PrintAllbooks(BTree L);
/*
	输出所有书的信息
*/
int ShowBookinfo(BTree L, int booknum);
/*
	输出指定某本书的信息
*/
void PrintBorrower(ReaderType R);
/*
	输出某本书的借阅者信息
*/



void InitLibrary(BTree &L) {
	L = NULL;
}

void InsertBook(BTree &L, BookType B, result res) {
	//书库L已存在，res包含B书在书库L中的位置或应该插入的位置
	//如果书库中已存在B书，则只将B书的库存量增加，否则插入B书到书库L中

	if (res.tag == 0) InsertBTree(L, B->booknum, res.pt, res.i, B);
	//书库中不存在该书，则插入
	else {
		BookType b = res.pt->recptr[res.i];
		b->current = b->current + B->total;//现存量增加
		b->total = b->total + B->total;//总库存增加
	}
}

int DeleteBook(BTree &L, BookType B) {
	//如果书库中存在B书，则从书库中删除B书的信息，并返回OK，否则返回ERROR
	if (DeleteBTree(L, B->booknum)) return OK;//删除成功
	else return ERROR;//删除失败
}

int CanBorrow(BTree L, BookType B, ReaderType R) {
	//如果书库中存在B书，若B书现存量大于0，则可出借返回OK，否则返回ERROR
	if(B->current>0) return TRUE;//现存量大于零
	else return FALSE;//其他情况均不允许出借
}

void	BorrowBook(BTree L, BookType B, ReaderType R)
// 书库L存在，B书是书库中的书并且可被读者R借阅（已通过CanBorrow()判断）
// 借出一本B书，登记借阅者R的信息，改变现存量，记录借书日期，最迟应还日期等信息。
{
	ReaderType	r;
	if (!B->reader) B->reader = R;				// 无其他借阅者，则直接登记
	else {
		for (r = B->reader; r->rnext; r = r->rnext);
		r->rnext = R;							// 否则到借阅者链表尾，登记
	}
	B->current--;								// 现存量减1

}

int ReturnBook(BTree L, int booknum, int IDnum, BookType &B, ReaderType &R) {
	//booknum为还书书号，IDnum是借阅者的ID号
	//若书库中不存在书号为booknum的书，则搜索出错，返回-1
	//若有借阅记录，则注销该记录，并用B和R返回图书信息和借阅者信息并返回1
	//若没有r借阅的记录，则用B返回图书信息，并返回0
	result res = SearchBTree(L, booknum); //在B树上按书号搜索
	if (res.tag == 0) return -1;
	B = res.pt->recptr[res.i];
	ReaderType p = res.pt->recptr[res.i]->reader, pre = p;
	while (p) {
		if (pre == p&&p->IDnum == IDnum) {
			R = p;
			B->current++;//现存量加一
			return 1;
		}
		if (p->IDnum == IDnum) {//多个借书者
			R = p;
			pre->rnext = p->rnext;
			B->current++;//现存量+1
			return 1;
		}
		pre = p;
		p = p->rnext;
	}
	return 0;
}

void PrintH() {//表格头部格式
	printf("\n");
	printf("|*********************************图书基本信息**********************************|\n"); 
	printf("|  书号  |       书名         |      作者     | 现存 | 总库存 | 出版年份 | 定价 |\n");
}

void PrintB(BookType B) { //显示B书基本信息
	printf("|--------|--------------------|---------------|------|--------|----------|------|\n");
	printf("|  %-4d  |%-20s|%-15s|", B->booknum,B->bookname,B->writer);
	printf(" %-5d|   %-4d | %-6d   |%-6.1f|\n",  B->current, B->total, B->published_year, B->price);
}

void PrintT() {//表格底部格式
	printf("|--------|--------------------|---------------|------|--------|----------|------|\n");
}

void PrintAll(BTree p) {//显示B树每个结点的记录信息
	int i;
	for (i = 1; i <= p->keynum; ++i) {
		PrintB(p->recptr[i]);
	}
}

void PrintBook(BookType B) {//以表格形式显示一本书的基本信息
	PrintH();
	PrintB(B);
	PrintT();
	printf("\n");
}

void PrintBorrower(ReaderType R) {//以表格形式显示一本书的借阅者信息
	ReaderType p = R;
	printf("|------------------------|\n");
	while (p) {
		printf("|  %-5d  |  %-10s  |\n", p->IDnum, p->reader_name);
		p = p->rnext;
	}
	printf("|------------------------|\n");
}

void PrintAllbooks(BTree L) {//显示书库L所有图书信息
	PrintH();
	BTreeTraverse(L, PrintAll);
	PrintT();
}

int ShowBookinfo(BTree L, int booknum) {
	//若书库L中存在书号为booknum的书，则现在该书的所有信息并返回OK，书库L不存在则
	//返回ERROR
	result res = SearchBTree(L, booknum);
	if (!res.tag) return ERROR;
	BookType B = res.pt->recptr[res.i];
	PrintBook(B);
	return OK;
}


/********************************B树接口实现****************************/

int Search(BTree p, int k) {
	//在B树p中查找关键字k的位置i，使得p->node[i].key<=K<p->node[i+1].key
	int i;
	for (i = 0; i < p->keynum&&p->key[i + 1] <= k; i++);
	return i;
}

result	SearchBTree(BTree T, KeyType k)
// 在m阶B树上查找关键字k，返回结果（pt，i，tag）。若查找成功，则特征值tag=1，指针pt
// 所指结点中第i个关键字等于k；否则返回特征值tag=0，等于k的关键字应插入在pt所指结点
// 中第i和第i+1个关键字之间。
{
	int		i = 1;
	BTree	p = T, q = NULL;						// 初始化，p指向待查结点，q指向p的双亲
	int		found = FALSE;
	while (p && !found)
	{
		i = Search(p, k);							// 查找k的位置使p->key[i]<=k<p->key[i+1]
		if (i> 0 && k == p->key[i])	found = TRUE;
		else {										// 未找到，则查找下一层
			q = p;
			p = p->ptr[i];
		}
	}
	if (found) { result	r = { p, i, 1 };	return r; }	// 查找成功
	else { result	r = { q, i, 0 };	return r; }	// 查找不成功，返回k的插入位置信息
}

void split(BTree &q, int s, BTree &ap) {
	//将q结点分裂成两个结点，前一半保留，后一半移入新结点ap
	int i, n = q->keynum;
	ap = (BTNode*)malloc(sizeof(BTNode));//生成新结点ap
	ap->ptr[0] = q->ptr[s];
	for (i = s + 1; i <= M; i++) {//后一半移入ap结点
		ap->key[i-s] = q->key[i];
		ap->ptr[i-s] = q->ptr[i];
		ap->recptr[i - s] = q->recptr[i];
	}
	ap->keynum = n - s;//计算ap的关键字个数
	ap->parent = q->parent;
	for (i = 0; i <= M - s; i++) {
		if (ap->ptr[i])
			ap->ptr[i]->parent = ap;//将ap所有孩子结点指向ap
	}
	q->keynum = s - 1;//q结点的前一半保留，修改keynum
}

void newroot(BTree &T, BTree p, int k, BTree ap,Record *recptr) {//生成新的根结点
	T = (BTNode*)malloc(sizeof(BTNode));
	T->keynum = 1;
	T->ptr[0] = p;
	T->ptr[1] = ap;
	T->key[1] = k;
	T->recptr[1] = recptr;  //T的子树ap的父亲指针
	if (p != NULL) p->parent = T;
	if (ap != NULL) ap->parent = T;
	T->parent = NULL;//新根的双亲是空指针
}

void Insert(BTree &q, int i, int k, BTree ap,Record *recptr) {//k和ap分别插到q->key[i+1]和q->ptr[i+1]
															//并插入关键字为k的记录recprt
	int j, n = q->keynum;
	for (j = n; j > i; j--) {
		q->key[j + 1] = q->key[j];//关键字指针向后移一位
		q->ptr[j + 1] = q->ptr[j];//孩子结点指针向后移一位
		q->recptr[j + 1] = q->recptr[j];
	}
	q->key[i+1] = k;//赋值
	q->ptr[i+1] = ap;
	q->recptr[i + 1] = recptr;
	if (ap != NULL) ap->parent = q;
	q->keynum++;//关键字数+1
}

Status InsertBTree(BTree &T, KeyType k, BTree q, int i, Record *rec)
//  在m阶B树T上结点*q的key[i]与key[i+1]之间插入关键字K和记录rec。
//  若引起结点过大，则沿双亲链进行必要的结点分裂调整，使T仍是m阶B树。
{
	BTree ap = NULL;
	int finished = FALSE;
	if (!q)    newroot(T, NULL, k, NULL, rec);	// T是空树，生成仅含关键字K的根结点*T
	else {
		while (!finished)
		{
			Insert(q, i, k, ap, rec);			// 将k和ap分别插入到q->key[i+1]和q->ptr[i+1]
			if (q->keynum < M) finished = TRUE; // 插入完成
			else {
				split(q, (M + 1) / 2, ap);			// 分裂结点Q
				k = q->key[(M + 1) / 2];
				rec = q->recptr[(M + 1) / 2];
				if (q->parent)
				{							// 在双亲结点*q中查找k的插入位置
					q = q->parent;
					i = Search(q, k);
				}
				else finished = OVERFLOW;		// 根节点已分裂为*q和*ap两个结点
			}
		}
		if (finished == OVERFLOW)				// 根结点已分裂为结点*q和*ap
			newroot(T, q, k, ap, rec);			// 需生成新根结点*T,q和ap为子树指针
	}
	return OK;
} //  InsertBTree



void TakePlace(BTree &q, int &i) {
	//*q结点的第i个关键字为k，用q的后继关键字代替q，且令q指向后继所在结点
	BTree p = q;
	q = q->ptr[i];
	while (q->ptr[0]) q = q->ptr[0]; //查找p的后继
	p->key[i] = q->key[1]; //记录代替
	p->recptr[i] = q->recptr[1];
	i = 1;  //代替后应该删除q所指结点的第1个关键字
}

void Del(BTree q, int i) {
	//删除q所指结点第i个关键字及其记录
	for (; i < q->keynum; i++) {//关键字和记录指针前移
		q->key[i] = q->key[i + 1];
		q->recptr[i] = q->recptr[i + 1];
	}
	q->keynum--;//关键字数目减1
}

Status	Borrow(BTree q)
// 若q的兄弟结点关键字大于(m-1)/2,则从兄弟结点上移最小（或最大）的关键字到双亲结点，
// 而将双亲结点中小于(或大于）且紧靠该关键字的关键字下移至q中,并返回OK，否则返回EREOR。
{
	int	i;
	BTree p = q->parent, b = NULL;					// p指向q的双亲结点
	for (i = 0; p->ptr[i] != q; i++);			// 查找q在双亲p的子树位置
	if (i >= 0 && i + 1 <= p->keynum && p->ptr[i + 1]->keynum > (M - 1) / 2)
	{										// 若q的右兄弟关键字个数大于(m-1)/2
		b = p->ptr[i + 1];						// b指向右兄弟结点
		q->ptr[1] = b->ptr[0];					// 子树指针也要同步移动
		q->key[1] = p->key[i + 1];				// 从父节点借第i+1个关键字
		q->recptr[1] = p->recptr[i + 1];
		p->key[i + 1] = b->key[1];				// b第一个关键字上移到父节点
		p->recptr[i + 1] = b->recptr[1];
		for (i = 1; i <= b->keynum; i++)			// b第一个关键字上移，需把剩余记录前移一位
		{
			b->key[i] = b->key[i + 1];
			b->recptr[i] = b->recptr[i + 1];
			b->ptr[i - 1] = b->ptr[i];
		}
	}
	else if (i > 0 && p->ptr[i - 1]->keynum > (M - 1) / 2)
	{										// 若q的左兄弟关键字个数大约(m-1)/2
		b = p->ptr[i - 1];						// b指向左兄弟结点
		q->ptr[1] = q->ptr[0];
		q->ptr[0] = b->ptr[b->keynum];
		q->key[1] = p->key[i];					// 从父节点借第i个关键字
		q->recptr[1] = p->recptr[i];
		p->key[i] = b->key[b->keynum];			// 将b最后一个关键字上移到父节点
		p->recptr[i] = b->recptr[b->keynum];
	}
	else return ERROR;							// 无关键字大于(m-1)/2的兄弟
	q->keynum++;
	b->keynum--;
	for (i = 0; i <= q->keynum; i++)
		if (q->ptr[i]) q->ptr[i]->parent = q;	// 刷新q的子结点的双亲指针
	return OK;
}

void Combine(BTree &q) {
	int i, j;
	BTree p = q->parent, b = NULL;//p指向q的父亲
	for (i = 0; p->ptr[i] != q; i++);//查找q在父亲p中的子树位置
	if (i == 0) {//若为0，则需合并为兄弟的第一个关键字
		b = p->ptr[i + 1];
			for (j = b->keynum; j >= 0; j--) {//将b的关键字和记录后移一位
				b->key[j + 1] = b->key[j];
				b->recptr[j + 1] = b->recptr[j];
				b->ptr[j + 1] = b->ptr[j];
			}
			b->ptr[0] = q->ptr[0];//合并
			b->key[1] = p->key[1];
			b->recptr[1] = p->recptr[1];
		}
	else if (i > 0) {//若q在父亲的子树位置大于0，需合并为兄弟b的最后一个关键字
		b = p->ptr[i - 1];
		b->key[b->keynum + 1] = p->key[i];//合并
		b->recptr[b->keynum + 1] = p->recptr[i];
		b->ptr[b->keynum + 1] = q->ptr[0];
	}
	if(i==0||i==1)//若i为0或1，需将父结点p关键字前移一位
		for (; i < p->keynum; i++) {
			p->key[i] = p->key[i + 1];
			p->ptr[i] = p->ptr[i + 1];
			p->recptr[i] = p->recptr[i + 1];
		}
	p->keynum--;
	b->keynum++;
	free(q);
	q = b;   //q指向修改的兄弟结点
	for (i = 0; i <= b->keynum; i++)
		if (b->ptr[i]) b->ptr[i]->parent = b;//刷新b的子结点的双亲指针
}


Status	DeleteBTree(BTree &T, KeyType k)
// 在m阶B树T上删除关键字k及其对应记录，并返回OK。
// 如T上不存在关键字k，则返回ERROR。
{
	KeyType	x = k;
	BTree	q, b = NULL;
	int		finished = FALSE, i = 1;
	result res = SearchBTree(T, k);				// 在T中查找关键字k
	if (res.tag == 0) return ERROR;				// 未搜索到
	else
	{
		q = res.pt;								// q指向待删结点
		i = res.i;
		if (q->ptr[0]) TakePlace(q, i);			// 若q的子树不空，(非底层结点)
												// 则以其后继代之，且令q指向后继所在结点
		Del(q, i);								// 删除q所指向结点中第i个关键字及记录
		if (q->keynum >= (M - 1) / 2 || !q->parent)		// 若删除后关键字个数不小于(m-1)/2或q是根节点
		{
			finished = TRUE;					// 删除完成
			if (q->keynum == 0) T = NULL;		// 若q的关键字个数为0 ，则为空树
		}
		while (!finished)
		{
			if (Borrow(q))	finished = TRUE;	// 若q的相邻兄弟结点关键字大于(m-1)/2,则从该
												// 兄弟结点上移一个最大（或最小）关键字到
												// 父节点，从父节点借一关键字到q
			else {								// 若q相邻兄弟关键字个数均等于┌m /2┑-1
				Combine(q);	// 将q中的剩余部分和双亲中的相关关键字合并至q的一个兄弟中
				q = q->parent;					// 检查双亲
				if (q == T && T->keynum == 0)	// 若被删结点的父节点是根T且T的关键字个数为0
				{
					T = T->ptr[0];				// 新根	
					T->parent = NULL;
					free(q);					// 删除原双亲结点
					finished = TRUE;
				}
				else if (q->keynum >= M / 2) finished = TRUE;
			}								// 合并后双亲关键字个数不少于(m-1)/2，完成
		}
	}
	return OK;
}


void BTreeTraverse(BTree T, void (*visit)(BTree )) {
	//遍历B树T，对每个结点调用visit函数
	if (!T) return;
	visit(T);
	for (int i = 0; i <= T->keynum; ++i) {
		if (T->ptr[i]) BTreeTraverse(T->ptr[i], visit);
	}
}

void	ShowBTree(BTree T, short  x)
// 递归以凹入表形式显示B树T,每层的缩进量为x，初始缩进量为8
{
	if (!T)	return;
	int		i;
	printf("\n");
	for (i = 0; i <= x; i++) putchar(' ');			// 缩进x
	for (i = 1; i <= T->keynum; i++)
	{
		printf("%d,", T->key[i]);
	}
	for (i = 0; i <= T->keynum; i++)				// 递归显示子树结点关键字
		ShowBTree(T->ptr[i], x + 7);
}

int menu() {//菜单
	int choice;
	printf("\n\n|**********************************************|\n");
	printf("|**********************************************|\n");
	printf("______________________________________________|\n");
	printf("|                 图书馆管理系统               |\n");
	printf("|                                              |\n");
	printf("|   1.采编入库           2.清除库存            |\n");
	printf("|                                              |\n");
	printf("|   3.借阅图书           4.归还图书            |\n");
	printf("|                                              |\n");
	printf("|   5.查看图书馆全部图书 6.查看某图书信息      |\n");
	printf("|                                              |\n");
	printf("|   7.查看某书借阅者信息 0.退出               |\n");
	printf("|                                              |\n");
	printf("|______________________________________________|\n");
	printf("|**********************************************|\n");
	printf("|**********************************************|\n");
	do {
		printf("请选择功能（输入0-8任意一个数字）:");
		scanf("%d", &choice);
	} while (choice < 0 || choice > 8);//避免非法输入
	return choice;
}




int login() {//登陆界面
	
	int secret_code, i;	
	printf("\n ______________________________________\n");
	printf("|                                      |\n");
	printf("|                                      |\n");
	printf("|         请输入图书管理员密码！       |\n");
	printf("|            密码：____                |\n");
	printf("|______________________________________|\n");
	scanf("%d", &secret_code);
	fflush(stdin);

	if (secret_code == Super_Manager_Code)//判断是不是管理员
		return 1;
	else
		return 0;
}

int main() {
	BTree L = NULL;
	BookType B;
	result res;
	ReaderType R;
	int booknum, IDnum, k, book_num;
	char flag;
	int i;
	if (login()) {
		for (;;) {
			switch (menu())
			{
			case 1://采编图书
				B = (BookType)malloc(sizeof(BookNode));
				B->reader = NULL;
				printf("请输入要入库的书号：\n");
				scanf("%d", &B->booknum);
				getchar();
				res = SearchBTree(L, B->booknum);
				if (!res.tag) {
					printf("请输入该书书名：\n");
					gets(B->bookname);
					printf("请输入该书作者：\n");
					gets(B->writer);
					printf("请输入入库数：\n");
					scanf("%d", &B->current);
					printf("请输入出版年份：\n");
					scanf("%d", &B->published_year);
					printf("请输入书本价格：\n");
					scanf("%f", &B->price);
					B->total = B->current;
					InsertBook(L, B, res);
					printf("用凹入表形式显示B树如下：\n");
					ShowBTree(L, 8);
					break;
				}
				else {//图书已存在，只增加库存
					printf("书库已有该书记录，请输入增加的册数：\n");
					scanf("%d", &B->total);
					InsertBook(L, B, res);
					B = res.pt->recptr[res.i];
					printf("用凹入表形式显示B树如下：\n");
					ShowBTree(L);
					printf("新书入库操作完成！\n");
					system("pause");
					break;
				}


			case 2://清空库存
				printf("请输入要删除的图书书号：\n");
				fflush(stdin);
				scanf("%d", &booknum);
				res = SearchBTree(L, booknum);
				if (res.tag) {
					B = res.pt->recptr[res.i];
					PrintBook(B);
					printf("\n您确认删除上面的图书<Y确认，其余按键返回主菜单>?");
					fflush(stdin);
					getchar();
					flag = getchar();
					if (flag == 'Y' || flag == 'y') {
						DeleteBook(L, B);
						printf("\n清除完毕！\t删除后用凹入表显示B树如下：\n");
						ShowBTree(L, 8);
					}
				}
				else {
					printf("\n书库不存在此书，删除失败！\n");
				}
				printf("\t");
				system("pause");
				break;
			case 3://借阅图书
				R = (ReaderType)malloc(sizeof(ReaderNode));
				R->rnext = NULL;
				printf("请输入借阅图书书号：\n");
				fflush(stdin);
				scanf("%d", &booknum);
				getchar();
				res = SearchBTree(L, booknum);
				if (res.tag) {
					B = res.pt->recptr[res.i];
					printf("请输入您的姓名：\n");
					fflush(stdin);
					gets(R->reader_name);
					printf("请输入您的ID号：\n");
					fflush(stdin);
					scanf("%d", &R->IDnum);
					if (CanBorrow(L, B, R)) {
						BorrowBook(L, B, R);
						printf("\n借书完成！");
					}
					else {
						printf("\n库存不足，借阅失败！");
						free(R);
					}
				}
				else {
					printf("\n库存无此书，借阅失败！");
					free(R);
				}
				printf("\t");
				system("pause");
				break;
			case 4://归还图书
				printf("\n请输入图书号：\n");
				scanf("%d", &booknum);
				printf("请输入您的ID号：\n");
				scanf("%d", &IDnum);
				k = ReturnBook(L, booknum, IDnum, B, R);
				if (k == 1) {
					printf("\n还书完成！");
					R = NULL;
				}
				else if (k == 0) {
					printf("\n还书失败，系统没有您借该书记录！");
				}
				else {
					printf("\n书库中不存在此书!");
				}
				printf("\t");
				system("pause");
				break;
			case 5://输出总库存
				printf("图书馆总库存信息如下：\n");
				PrintAllbooks(L);
				break;
			case 6://查找某种图书
				printf("请输入要查找的图书的编号：\n");
				scanf("%d", &book_num);
				ShowBookinfo(L, book_num);
				break;
			case 7://输出某图书的借阅者信息
				printf("请输入要查找的图书的编号：\n");
				scanf("%d", &book_num);
				res = SearchBTree(L, book_num);
				if (res.tag) {
					B = res.pt->recptr[res.i];
					printf("借阅者信息如下：\n");
					PrintBorrower(B->reader);
				}
				else {
					printf("\n书库不存在此书，查找失败！\n");
				}
				printf("\t");
				system("pause");
				break;
			case 0:  //退出管理系统
				exit(0);
			default:
				break;
			}
		}
	}
	else {
		printf("密码输入错误！\n");
		system("pause");
	}
	return 0;
}