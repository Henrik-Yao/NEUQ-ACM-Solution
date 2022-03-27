### **图的创建**

记录每个起点的出度，用结构体数组存储起点，终点，权值，将数组按起点顺序，起点相同时按终点顺序排序。最后输出即可。

```c++
#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int w;
	int y;
};
struct node a[20010];
int s[21010]={0};
int cmp(const void *a,const void *b){
	struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(c->t!= d->t) return c->t-d->t;
    else return c->w-d->w;
}
int main(){
	int n,e,sum;
	cin>>n>>e;
    for(int i =0; i<e; i++)
    { 
    	a[i].t = -1;
        a[i].w = -1;
        a[i].y = -1;
    }
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
		s[a[i].t]++;
	}
	qsort(a,e,sizeof(a[0]),cmp);
	int i = 0;
	while(i<e){
		sum = s[a[i].t];
		printf("%d:",a[i].t);
		for(int j = i;j<sum+i;j++){
			printf(%d,%d,%d)",a[j].t,a[j].w,a[j].y);
		}
		i = i+sum;
		printf("\n");
	}
	return 0; 
}
```

### **图的删边操作**

与上一题类似，特殊的是，将第二次输入的路标记，输出时不输出该路即可。

```c++
#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int w;
	int y;
};
struct node a[20010];
int s[21010]={0},s1[21010]={0};
int cmp(const void *a,const void *b){
	struct node *c = (node *)a;
    struct node *d = (node *)b;
    if(c->t!= d->t) return c->t-d->t;
    else return c->w-d->w;
}
int main(){
	int n,e,sum,k,q1,q2;
	cin>>n>>e;
    for(int i =0; i<e; i++)
    { 
    	a[i].t = -1;
        a[i].w = -1;
        a[i].y = -1;
    }
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
		s[a[i].t]++;s1[a[i].t]=s[a[i].t];
	}
	qsort(a,e,sizeof(a[0]),cmp);
/**/	cin>>k;
	for(int i=0;i<k;i++){
		cin>>q1>>q2;
		for(int j=0;j<e;j++){
			if(q1==a[j].t&&q2==a[j].w){
				a[j].w=-1;s1[a[j].t]--;
			}
		}
		
	}
	
	int i = 0;
	while(i<e){
		sum = s[a[i].t];
        if(s1[a[i].t]){
		printf("%d:",a[i].t);
		for(int j = i;j<sum+i;j++){
			if(a[j].w!=-1)
			printf("(%d,%d,%d)",a[j].t,a[j].w,a[j].y);
		}
		printf("\n");            
        }
		i = i+sum;
	}
	return 0; 
}
```

### **岛屿数量**

搜索，直到遇到水停止后，ans++。

```c++
#include<bits/stdc++.h>
using namespace std;
bool s[2005][2005],p[2005][2005];
int sum=0;
void dfs(int a,int b){
	if(s[a-1][b])s[a-1][b]=0,dfs(a-1,b);
	if(s[a+1][b])s[a+1][b]=0,dfs(a+1,b);
	if(s[a][b-1])s[a][b-1]=0,dfs(a,b-1);
	if(s[a][b+1])s[a][b+1]=0,dfs(a,b+1);

	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	for(int j=0;j<=m+1;j++)
	s[i][j]=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)	
	cin>>s[i][j],p[i][j]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(s[i][j]&&p[i][j]){dfs(i,j);sum++;}
	cout<<sum;
	return 0;
}
```

### **繁忙的都市**

最小生成树问题。

```c++
#include<bits/stdc++.h>
using namespace std;
int p[1000],ans,maxx,n;
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
struct node{
	int t;
	int w;
	int y;
	bool operator<(const node&t)const{
	        return y<t.y;
	    }
};
struct node a[20010];


int main(){
	int e;
	cin>>n>>e;
    for(int i=1;i<=n;i++)
    p[i]=i;    
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
	}
	sort(a,a+e);
	ans=0;
	    for(int i=0;i<e;i++){
        int q1=find(a[i].t),q2=find(a[i].w),q3=a[i].y;
        if(q1!=q2){
            p[q1]=q2;
            ans=q3;
        }
    }
	cout<<n-1<<" "<<ans;
	return 0; 
}
```

### **最小支撑树**

与上一题类似，更改输出量即可

```c++
#include<bits/stdc++.h>
using namespace std;
int p[1501],ans,maxx,n,q[1501],p3,p2,nextt[1501];
int find(int x){
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
struct node{
	int t;
	int w;
	int y;
	int nex;
	bool operator<(const node&t)const{
	        return y<t.y;
	    }
};struct node a[20010];
void f(int x){

}
int main(){
	int e;
	while(cin>>n>>e){
		p3=1;p2=1;
		int sum=0;
    for(int i=0;i<1500;i++)
        p[i]=0;
    for(int i=1;i<=n;i++)
    p[i]=i;    
	for(int i= 0;i<e;i++){
		cin>>a[i].t>>a[i].w>>a[i].y;
	}
	sort(a,a+e);
	ans=0;
	    for(int i=0;i<e;i++){
	    	a[i].nex=a[i].w;
        int q1=find(a[i].t),q2=find(a[i].w),q3=a[i].y;
        if(q1!=q2){
            p[q1]=q2;
            ans=q3;
        }
        else a[i].nex=0;
    }
		for(int i=0;i<e;i++){
			if(a[i].y<=ans) sum+=a[i].y;
			else break;
		}
		for(int i=2;i<n;i++)
		q[i]=0;q[1]=1;
		for(int i=0;i<e;i++){
			q[a[i].nex]=1;//cout<<a[i].nex<<" "<<q[a[i].nex]<<endl;
		}
		for(int i=0;i<n;i++){
            
			if(!q[i]){p3=0;cout<<"There is no minimum spanning tree."<<endl;break;}
		}
		if(p3)cout<<sum<<endl;
		for(int i= 0;i<e;i++){
			a[i].t=a[i].w=a[i].y=0;
		}	
	}
	return 0; 
}
```

### **特殊最小成本修路**

与上一题类似，对城市v的路，只进行2次运算。

```c++
#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int u;//顶点1
	int v;//顶点2 
	int w;//权值 
}Edge;//结构体存边的信息 
int a[201];
int pp;
bool cmp(Edge edge1,Edge edge2){
	return edge1.w<edge2.w;
}

void init(){//初始化 
	for(int i=0; i<201; i++){
		a[i] = i;
	}
}

int find(int x){//查找 
	int r = x;
	while(a[r]!=r)
		r = a[r];
	return r;
}

int join(int x,int y){//合并 
	int fx = find(x);
	int fy = find(y);
	if(fx!=fy&&pp){
		pp--;
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main(){
    int n,e,v;
    while(cin >> n>>v >> e){
    	Edge edge[e];pp=2;
    	init();
    	for(int i=0; i<e; i++){
    		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		}
		sort(edge,edge+e,cmp); //边按权值从小到大排序 
		int cnt=0, w_sum=0; //边数、权值和
		for(int i=0; i<e; i++){
			if(edge[i].u==v||edge[i].v==v){
				int fx = find(edge[i].u);
				int fy = find(edge[i].v);
				if(fx!=fy&&pp){
					pp--;
					a[fy] = fx;
					cnt++;
					w_sum += edge[i].w;						
				}

				}
				else if(edge[i].u!=v&&edge[i].v!=v){
					int fx = find(edge[i].u);
					int fy = find(edge[i].v);
					if(fx!=fy){				
					cnt++;
					w_sum += edge[i].w;
					a[fy]=fx;					
				}
				
			}
			if(cnt==n-1) //边数 = 顶点数-1，找到最小生成树 
				break;
		}
		if(cnt==n-1)
			cout << w_sum << endl;
		else cout << -1 << endl; 
	}
    return 0;
}
```

