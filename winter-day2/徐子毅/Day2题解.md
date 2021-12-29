***

# **7-1 二叉树叶结点值和最大层**

> 已知一棵非空二叉树结点的数据域为不等于0的整数，请编写程序找出该二叉树中叶结点数据值之和最大的层。
>
> ### 输入格式:
>
> 输入为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。
>
> ### 输出格式:
>
> 输出为一个整数，表示叶结点数据值之和最大的层，如果存在多个满足条件的层，则输出最下面一层。
>
> ### 输入样例1:
>
> ```in
> 1 2 0 0 3 0 0
> ```
>
> ### 输出样例1
>
> ```out
> 1
> ```
>
> ### 输入样例2:
>
> ```in
> 1 -2 0 0 3 -1 0 0 -1 0 0
> ```
>
> ### 输出样例2:
>
> ```out
> 2
> ```

一个简单的构造树的题，需要记录每个数据的层数。

```C++
#include <iostream>
using namespace std;
struct tree{
	int data;
	tree * lchild;
	tree * rchild;
	int level;
};
int sum[105];
int num[105];
int maxlevel=-1;
tree * createtree(int level){
	int n;
	cin >> n;
	if(n==0) return NULL;
	else{
		tree * BT = new tree;
		BT->data=n;
		BT->level=level;
		if(level>maxlevel) maxlevel=level;
		BT->lchild=createtree(level+1);
		BT->rchild=createtree(level+1);
		return BT;
	}
}
void GETBEST(tree * BT){
	if(BT==NULL) return;
	else{
		if(BT->lchild==NULL&&BT->rchild==NULL){
			sum[BT->level]+=BT->data;
			num[BT->level]++;
		}
		GETBEST(BT->lchild);
		GETBEST(BT->rchild);
	}
}
int main(){
	tree * root=createtree(0);
	GETBEST(root);
	int _max_SUM=-9999;int goodlevel=0;
	for(int i=0;i<=maxlevel;i++){
		if(sum[i]>=_max_SUM&&num[i]){
			_max_SUM=sum[i];
			goodlevel=i;
		}
	}
	cout << goodlevel << endl;
	return 0;
}
```

***

# **7-2 重建二叉树**

> 给定非空二叉树的中根序列和后根序列，请编写程序创建该二叉树，计算其高度和先根序列，最后删除该二叉树；如给定的中根和后根序列不合法，则亦能识别。
>
> ### 输入格式:
>
> 输入包含多组数据（不超过10组），每组为两行字符串，第一行表示某二叉树的后根序列，第二行表示其中根序列。结点的值均为A-Z的大写字母，故二叉树结点个数不超过26，且保证输入的两个序列都是结点的全排列，但不一定是合法的中根和后根序列。输入保证不是空二叉树。
>
> ### 输出格式:
>
> 对于每组数据，如果输入的序列不合法（不是同一棵树的中根序列和后根序列），则输出INVALID；若输入序列合法，输出为两行，第一行为一个整数，表示该二叉树的高度，第二行为一个字符串，表示该二叉树的先根序列。
>
> ### 输入样例1:
>
> ```in
> CEFDBHGA
> CBEDFAGH
> CBEDFAGH
> CEFDBHGA
> BCA 
> CAB
> ```
>
> ### 输出样例1:
>
> ```out
> 3
> ABCDEFGH
> INVALID
> INVALID
> ```

这道题就把后根序列组合出来就行了。

合法的判断就是每一个中序根节点左侧和后序的左侧是否匹配即可。

```C++
#include <iostream>
#include <cstring>
using namespace std;
struct tree{
	char data;
	tree * lchild;
	tree * rchild;
};
string post;
string in;
bool judge(string a,string b){
	if(a.size()==0 && b.size()==0) return true;
	if(a.size()!=b.size()) return false;
	char ch;
	ch = a[a.size()-1];
	int i=0;
	for(i=0;i<b.size();i++) if(b[i]==ch) break;
	string al=a.substr(0,i),ar=a.substr(i,a.size()-1-i);
	string bl=b.substr(0,i),br=b.substr(i+1,a.size());
	for(int i=0;i<al.size();i++){
		if(bl.find(al[i])==-1) return false;
	}
	for(int i=0;i<ar.size();i++){
		if(br.find(ar[i])==-1) return false;
	}
	return judge(al,bl) && judge(ar,br);
}
tree * createfront(int postfront,int postend,int infront,int inend){
	if(postfront>postend||infront>inend) return NULL;
	if(postfront==postend&&infront==inend){
		tree * leave=new tree;
		leave->data=post[postend];
		leave->lchild=NULL;
		leave->rchild=NULL;
		return leave;
	}
	char chroot=post[postend];
	int i;
	for(i=postfront;i<=postend;i++) if(in[i]==chroot) break;
	tree * BT=new tree;
	BT->data=chroot;
	BT->lchild=createfront(postfront,postfront+i-infront-1,infront,i-1);
	BT->rchild=createfront(postend+i-inend,postend-1,i+1,inend);
	return BT;
}
int gethigh(tree *BT){
	if(!BT){
		return 0;
	}
	int left=gethigh(BT->lchild);
	int right=gethigh(BT->rchild);
	return max(left,right)+1;
}
void pre(tree *BT){
	if(!BT) return;
	cout << BT->data;
	pre(BT->lchild);
	pre(BT->rchild);
}
int main(){
	int n;
	while(cin>>post>>in){
		if(judge(post,in)==false){
			cout << "INVALID" << endl;
			continue;
		}else{
			tree * root =new tree;
			root=createfront(0,post.size()-1,0,in.size()-1);
			cout << gethigh(root)-1 << endl;
			pre(root);
			cout << endl;
		}
	}
}
```

***

# **7-3 树最近公共祖先**

> 已知树结点为互不相等且不等于0的整数。请编写程序找出非空树中两个结点的最近公共祖先。例如对于图1(a)所示的树t，结点1和2的最近公共祖先是5；结点2和4的最近公共祖先是8。
>
> ![tree.jpg](https://images.ptausercontent.com/43e51246-40dc-4ad6-99f3-df4fad65f182.jpg)
>
> ### 输入格式:
>
> 每个测试点包含多组数据，第1行为一个正整数T，表示数组组数。每组数据为2行，第1行为一组用空格间隔的整数，个数不超过100个，表示带空指针信息的二叉树先根序列。其中空指针信息用0表示。第2行为空格间隔的两个互不相等的整数A和B，表示给定的两个结点值，保证A和B肯定在输入的树中。
>
> 注：我们已知二叉树与其自然对应的树相比，二叉树中结点的左孩子对应树中结点的左孩子，二叉树中结点的右孩子对应树中结点的右兄弟。进而我们可以利用“带空指针信息的先根序列构建二叉树”的方法来构建其对应的树的左孩子-右兄弟存储结构。如8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0对应图1(a)所示的树，1 2 0 3 0 4 0 0 0对应如图1(b)所示的树。
>
> ### 输出格式:
>
> 对每组数据输出一行，为一个整数，表示A和B的最近公共祖先结点的值。
>
> ### 输入样例1:
>
> ```in
> 2
> 8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
> 1 2
> 8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
> 2 4
> ```
>
> ### 输出样例1:
>
> ```out
> 5
> 8
> ```

~~什么祖宗题Debug了我好久~~

这个题就是要把左孩子-右兄弟的图给拆出来，用堆栈可以把这个树化为二叉树。

而这道题的特点在于数字的唯一性（负数直接加5000）所以可以用数组来存储每一个数的父亲和层数。

``` C++
#include <iostream>
#include <stack>
using namespace std;
int main(){
	int T;
	cin >> T;
	for(int TT=1;TT<=T;TT++){
		int father[10005],level[10005],n=1;
		stack<int> st;
		int num=0;
		cin >> num;
        if(num<0) num+=5000;
		level[num]=n++;
		st.push(num);
		while(!st.empty()){
			cin >> num;
            if(num<0) num+=5000;
			if(num!=0){
				father[num]=st.top();
				level[num]=n++;
				st.push(num);
			}else{
				n--;
				st.pop();
			}
		}
		int n1,n2;
		cin >> n1;
		cin >> n1 >> n2;
        if(n1<0) n1+=5000;
        if(n2<0) n2+=5000;
		if(level[n1]>level[n2]){
			int level_jump=level[n1]-level[n2];
			while(level_jump--){
				n1=father[n1];
			}
		}
		if(level[n1]<level[n2]){
			int level_jump=level[n2]-level[n1];
			while(level_jump--){
				n2=father[n2];
			}
		}
		while(n1!=n2){
			n1=father[n1];
			n2=father[n2];
		}
		cout << n1 << endl;
	}
}
```

***

# **7-4 罪犯帮派**

> Tabu市的警察局决定结束混乱，因此要采取行动根除城市中的几大帮派。目前的问题是，给出两个罪犯，他们是属于同一帮派么？城市里一共有多少个帮派？假设在Tabu市现有n名罪犯，编号为1到n，给出m条消息表示属于同一帮派的两个罪犯编号。请基于这些不完全的信息帮助警方计算出他们想要的信息。
>
> ### 输入格式:
>
> 输入第一行为三个正整数，n、m和q。n为罪犯数；m为给出的已知信息数量；q为查询数。接下来m行，每行2个正整数a和b，表示罪犯a和罪犯b属于同一帮派。接下来q行，每行2个正整数c和d，即查询罪犯c和d是否属于同一帮派。每行输入的整数以空格间隔，n、m、q均不超过1000。
>
> ### 输出格式:
>
> 输出为q+1行，前q行对应于输入的q个查询的结果，如果属于同一帮派，则输出“In the same gang.”，否则输出“In different gangs.”。最后一行为一个整数，表示帮派数目。
>
> ### 输入样例:
>
> ```in
> 3 2 1
> 1 2
> 2 3
> 1 3
> ```
>
> ### 输出样例:
>
> ```out
> In the same gang.
> 1
> ```

我太菜了，只能写朴素算法。。。

~~原来一个人也能算一个帮派啊。~~

```C++
#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> Group[1005];
map<int,int> GetGroup;
int geted[1005];
int main(){
	int n,m,q;
	cin >> n >> m >> q;
	int maxgroup=0;
	int p1,p2;
	for(int T=1;T<=m;T++){
		cin >> p1 >> p2;
		if(geted[p1]==1&&geted[p2]==1) {
			if(GetGroup[p1]==GetGroup[p2]) continue;
			else {
				int BigGroup;
				int SmallGroup;
				if(GetGroup[p1]>GetGroup[p2]){
					BigGroup=GetGroup[p1];
					SmallGroup=GetGroup[p2];
				}else{
					BigGroup=GetGroup[p2];
					SmallGroup=GetGroup[p1];
				}
				for(int i=0;i<Group[BigGroup].size();i++){
					Group[SmallGroup].push_back(Group[BigGroup][i]);
					GetGroup[Group[BigGroup][i]]=SmallGroup;
				}
				Group[BigGroup].clear();
			}
		}
		else if(geted[p1]==1&&geted[p2]==0){
			Group[GetGroup[p1]].push_back(p2);
			GetGroup[p2]=GetGroup[p1];
			geted[p2]=1;
		}else if(geted[p1]==0&&geted[p2]==1){
			Group[GetGroup[p2]].push_back(p1);
			GetGroup[p1]=GetGroup[p2];
			geted[p1]=1;
		}
		else if(geted[p1]==0&&geted[p2]==0){
			maxgroup++;
			Group[maxgroup].push_back(p1);
			Group[maxgroup].push_back(p2);
			GetGroup[p1]=maxgroup;
			GetGroup[p2]=maxgroup;
			geted[p1]=1;
			geted[p2]=1;
		}
	}
	int undefined=n;
	for(int i=1;i<=1005;i++) if(geted[i]==1) undefined--;
	for(int T=1;T<=q;T++){
		int id1,id2;
		cin >> id1 >> id2;
		bool _find=false;
		for(int i=0;i<Group[GetGroup[id1]].size();i++){
			if(Group[GetGroup[id1]][i]==id2){
				_find=true;
				cout << "In the same gang." << endl;
			}
		}
		if(!_find) cout << "In different gangs." << endl;
	}
	int sumgroup=0;
	for(int i=0;i<=1005;i++) if(!Group[i].empty()) sumgroup++;
	cout << sumgroup+undefined << endl;
}
```

***

# **7-6 先序和中序构造二叉树**

> 本题目要求用先序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其后序序列。
>
> ### 输入格式:
>
> 在第一行中输入元素个数。
>
> 第二行中输入先序序列，用空格分隔。
>
> 第三行中输入中序序列，用空格分隔。
>
> ### 输出格式:
>
> 输出此二叉树的后序序列，用空格分隔，最后也有一个空格。
>
> ### 输入样例:
>
> ```in
> 5
> 10 20 30 40 50
> 20 10 40 30 50
> 结尾无空行
> ```
>
> ### 输出样例:
>
> ```out
> 20 40 50 30 10 
> 结尾无空行
> ```

和7-3一样，通过从先序序列获取根节点，在通过中序序列拆出左子树和右子树。

```C++
#include <iostream>
using namespace std;
struct tree{
	int data;
	tree * lchild;
	tree * rchild;
};
int n;
tree * createtree(int prestart,int preend,int instart,int inend,int pre[],int in[]){
	tree * BT = new tree;
	if(prestart>preend||instart>inend) return NULL;
	if(prestart==preend&&instart==inend){
		BT->lchild=NULL;
		BT->rchild=NULL;
		BT->data=pre[prestart];
		return BT;
	}
	int front=pre[prestart];int i;
	for(i=0;i<n;i++) if(in[i]==front) break;
	int partleft=i-instart;
	int partright=inend-i;
	BT->data=front;
	BT->lchild=createtree(prestart+1,prestart+partleft,instart,i-1,pre,in);
	BT->rchild=createtree(prestart+1+partleft,prestart+partleft+partright,i+1,i+partright,pre,in);
	return BT;
}
void printtree(tree *BT){
	if(!BT) return;
	else{
		printtree(BT->lchild);
		printtree(BT->rchild);
		cout << BT->data << " ";
	}
}
int main(){
	cin >> n;
	int pre[n],in[n];
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>in[i];
	tree * ROOT=new tree;
	ROOT=createtree(0,n-1,0,n-1,pre,in);
	printtree(ROOT);
	cout << endl;
	return 0;
}
```

***

# 7-7 按层遍历二叉树

> 用先序和中序序列构造一棵二叉树（树中结点个数不超过10个），通过用队记录结点访问次序的方法实现对二叉树进行按层遍历，即按层数由小到大、同层由左到右输出按层遍历序列。
>
> ### 输入格式:
>
> 第一行输入元素个数
>
> 第二行输入先序序列，以空格隔开
>
> 第三行输入中序序列，以空格隔开
>
> ### 输出格式:
>
> 输出此二叉树的按层遍历序列，以空格隔开，最后也有一个空格。
>
> ### 输入样例:
>
> ```in
> 5
> 10 20 40 30 50
> 20 40 10 50 30
> 结尾无空行
> ```
>
> ### 输出样例:
>
> ```out
> 10 20 30 40 50 
> 结尾无空行
> ```

按层遍历的方法就是队列，首先将根节点入队，然后把后续节点入队，入队前先输出，然后在把所有子节点入队即可。

```C++
#include <iostream>
#include <queue>
using namespace std;
struct tree{
	int data;
	tree * lchild;
	tree * rchild;
};
queue<tree> lookup;
int n;
tree * createtree(int prestart,int preend,int instart,int inend,int pre[],int in[]){
	tree * BT = new tree;
	if(prestart>preend||instart>inend) return NULL;
	if(prestart==preend&&instart==inend){
		BT->lchild=NULL;
		BT->rchild=NULL;
		BT->data=pre[prestart];
		return BT;
	}
	int front=pre[prestart];int i;
	for(i=0;i<n;i++) if(in[i]==front) break;
	int partleft=i-instart;
	int partright=inend-i;
	BT->data=front;
	BT->lchild=createtree(prestart+1,prestart+partleft,instart,i-1,pre,in);
	BT->rchild=createtree(prestart+1+partleft,prestart+partleft+partright,i+1,i+partright,pre,in);
	return BT;
}
void printtree(tree *BT){
	
}
int main(){
	cin >> n;
	int pre[n],in[n];
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>in[i];
	tree * ROOT=new tree;
	ROOT=createtree(0,n-1,0,n-1,pre,in);
	lookup.push(*ROOT);
	while(!lookup.empty()){
		tree *TOP=&lookup.front();
		cout << TOP->data << " ";
		if(TOP->lchild!=NULL) lookup.push(*TOP->lchild); 
		if(TOP->rchild!=NULL) lookup.push(*TOP->rchild); 
		lookup.pop();
	}
	cout << endl;
	return 0;
}
```

***

# **7-8 中序遍历二叉树**

> 按完全二叉树的层次遍历给出一棵二叉树的遍历序列（其中用0表示虚结点），要求输出该二叉树的深度及中序遍历该二叉树得到的序列。
>
> ### 输入格式:
>
> 首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n（n≤1000），代表给出的二叉树的结点总数（当然，其中可能包含虚结点）。结点编号均为正整数,且各不相同。 然后输入n个正整数，表示按完全二叉树（即第1层1个结点，第2层2个，第3层4个，第4层有8个……）的层次遍历给出的二叉树遍历序列，如果某个结点不存在（虚结点），则以0代替。
>
> ### 输出格式:
>
> 对于每组测试，第一行输出中序遍历二叉树得到的序列（每两个数据之间留一个空格），第二行输出二叉树的深度。
>
> ### 输入样例:
>
> ```in
> 2
> 1 1
> 4 1 4 0 2
> ```
>
> ### 输出样例:
>
> ```out
> 1
> 1
> 2 4 1
> 3
> ```

通过层次序列构建二叉树值得注意的两点是：一个节点的父节点编号为i/2,一个节点的子节点编号为2\*i+1和2\*i。

```C++
#include <iostream>
#include <vector>
using namespace std;
vector<int> inqueue;
struct tree{
	int data;
	tree * lchild=NULL;
	tree * rchild=NULL;
};
void INBT(tree *BT){
	if(!BT) return;
	else{
		INBT(BT->lchild);
		inqueue.push_back(BT->data);
		INBT(BT->rchild);
	}
}
int GETHIGH(tree *BT){
	if(!BT) return 0;
	else return max(GETHIGH(BT->lchild),GETHIGH(BT->rchild))+1;
}
int main(){
	int T;int n;int nums;
	cin >> T;
	for(int abcdefg=0;abcdefg<T;abcdefg++){
		cin >> n;
		tree * btree[n+1];
		for(int i=0;i<=n;i++) btree[i]=new tree;
		cin >> nums;
		btree[1]->data=nums;
		for(int i=2;i<=n;i++){
			int num;
			cin >> num;
			if(num!=0) {
				btree[i]->data=num;
				if(i%2==0) btree[i/2]->lchild=btree[i];
				else btree[i/2]->rchild=btree[i];
			}else{
				if(i%2==0) btree[i/2]->lchild=NULL;
				else btree[i/2]->rchild=NULL;
			}
		}
		inqueue.clear();
		INBT(btree[1]);
		if(!inqueue.empty()) cout << inqueue[0];
		for(int i=1;i<inqueue.size();i++) cout << " " << inqueue[i];
		cout << endl;
		// int level=1;int double2=2;
		// while(double2<=n){
		// 	level++;
		// 	double2*=2;
		// }
		cout << GETHIGH(btree[1]) << endl;
	}
}
```

***

# **7-9 后序和中序构造二叉树**

> 本题目要求用后序序列和中序序列构造一棵二叉树（树中结点个数不超过10个），并输出其先序序列。
>
> ### 输入格式:
>
> 在第一行中输入元素个数。
>
> 第二行中输入后序序列，用空格分隔。
>
> 第三行中输入中序序列，用空格分隔。
>
> ### 输出格式:
>
> 输出此二叉树的先序序列，用空格分隔，最后也有一个空格。
>
> ### 输入样例:
>
> ```in
> 5
> 20 40 50 30 10
> 20 10 40 30 50
> 结尾无空行
> ```
>
> ### 输出样例:
>
> ```out
> 10 20 30 40 50 
> 结尾无空行
> ```

同7-3和7-6。

通过后序找根节点，再从中序拆分左右。

```C++
#include <iostream>
#include <vector>
using namespace std;
vector<int> inqueue;
struct tree{
	int data;
	tree * lchild=NULL;
	tree * rchild=NULL;
};
tree * createfront(int postfront,int postend,int infront,int inend,int post[],int in[]){
	if(postfront>postend||infront>inend) return NULL;
	if(postfront==postend&&infront==inend){
		tree * leave=new tree;
		leave->data=post[postend];
		leave->lchild=NULL;
		leave->rchild=NULL;
		return leave;
	}
	int chroot=post[postend];
	int i;
	for(i=postfront;i<=postend;i++) if(in[i]==chroot) break;
	tree * BT=new tree;
	BT->data=chroot;
	BT->lchild=createfront(postfront,postfront+i-infront-1,infront,i-1,post,in);
	BT->rchild=createfront(postend+i-inend,postend-1,i+1,inend,post,in);
	return BT;
}
void pre(tree *BT){
	if(!BT) return;
	else{
		cout << BT->data << " ";
		pre(BT->lchild);
		pre(BT->rchild);
	}
}
int main(){
	int n;
	cin >> n;
	int post[n],in[n];
	for(int i=0;i<n;i++) cin >> post[i];
	for(int i=0;i<n;i++) cin >> in[i];
	tree * root=new tree;
	root=createfront(0,n-1,0,n-1,post,in);
	pre(root);
	return 0;
}
```

