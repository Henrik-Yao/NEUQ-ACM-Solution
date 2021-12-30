**7-1 相邻数对**

先sort,再比较比纯暴力优化了些

**7-3 两个有序序列的中位数**

直接数组模拟就好了，无脑做

##### 二分查找

两道题做法类似放在一起。

模板题。

核心代码：

int l=0,r=n-1; while(l<=r) { int mid=(l+r)/2; ans++; if(x==a[mid]) { cout<<mid<<endl; pd=1; break; } if(x>a[mid]) { l=mid+1; } if(x<a[mid]) { r=mid-1; } }

**7-5 冰岛人**

采用vector<vector>+map对string进行映射+并查集寻找公共祖先处理。

储存数据：

struct people { int sex; int id; }; map<string,people>mp1;

并查集：

int find(int x) { int rt = fa[x]; if (fa[x] != x) rt = find(fa[x]); return rt; }

判断是否为五代以内：

bool pd(int x,int y) { int cnt=1; while(x!=fa[x]&&y!=fa[y]) { x=fa[x]; y=fa[y]; ++cnt; if(cnt==5) { //	cout<<"cnt"<<cnt<<endl; return 1; } if(x==y) { //	cout<<"cnt"<<cnt<<endl; return 0; } } return 0; }

**7-7 愤怒的牛**

先sort排序，后二分答案：



