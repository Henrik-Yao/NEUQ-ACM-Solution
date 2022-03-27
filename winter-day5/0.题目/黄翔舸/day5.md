​                                                                                   day5

1.顺序查找即可。

#include <iostream>  
#include <string.h>  
using namespace std;  

int main() {  
    int a[10005], i;  
    memset(a,0,sizeof(int)*10005);  
    int n;  
    cin >> n;  
    int num,count=0;  
    for ( i=0;i<n;i++) {  
        cin >> num;  
        a[num]++;  
    }  
    for (i=0;i<10004;i++){  
        if (a[i] && a[i+1])  
            count++;  
    }  
    cout << count << endl;  
    return 0;  
}  

3.

思路：求中位数，典型的二分查找。

#include<iostream>
using namespace std;

int main()
{
	int a[200002], c[100001], i, n, j = 0, k = 0;

	cin >> n;
	for (i = 0; i < 2 * n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++) {
		if (a[k] < a[n + j]) {
			c[i] = a[k];
			k++;
		}
		else {
			c[i] = a[n + j];
			j++;
		}
	}
	cout << c[n - 1];
	
	return 0;
}

4.

思路：二分查找

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    int cnt = 1;
    int p;
    for (int i = 0, j = n - 1;; cnt++) {
        p = (i + j) / 2;
      
        if (a[p] == x) {
            
            cout << p << endl << cnt; break;
        }
        else if (a[p] < x) {
          
            i = p + 1;
        }
        else {
    
            j = p - 1;
        }
        if (i > j) {
            cout << -1 << endl << cnt;
            break;
        }
    
    }
}

5

思路：注意查找的条件和判断是否存在，下面有分布注释。

#include<bits/stdc++.h>
using namespace std;
struct people{
	char sex;
	string father;
};
map<string,people> mp;
int panduan(string a,string b){
	int i = 1,j;
	for(string A = a;!A.empty();A = mp[A].father,i++){
		j = 1;
		for(string B = b;!B.empty();B = mp[B].father,j++){	//各自比较五代 
			if(i >= 5&&j >= 5)	//五代都没有，就可以交往 
				return 1;
			if(A==B && (i<5||j<5))	//五代内出现相同祖先，不可交往 
				return 0;
		}
	}
	return 1;	//不够五代，且没有共同祖先，可交往 
}
int main(){
	int N;
	cin.sync_with_stdio(false);	//这句不能少，要不然运行超时
	cin >> N;
	string a,b;
	for(int i = 0;i < N;i++){
		cin >> a >> b;
		if(b.back() == 'r'){	//维京女生 
			mp[a] = {'f',b.substr(0,b.size()-7)};	//父亲的名字是女生的姓，去掉"sdottir" 
		}else if(b.back() == 'n') {	//维京男生 
			mp[a] = {'m',b.substr(0,b.size()-4)};	//父亲的名字是男生的姓，去掉"sson" 
		}else{	//不是本地的，直接用最后一位判断性别，不需要知道父亲 
			mp[a].sex = b.back();
		}
	}
	int M;
	cin >> M;
	string str;
	for(int i = 0;i < M;i++){
		cin >> a >> str >> b >> str;
		if(mp.find(a) == mp.end() || mp.find(b) == mp.end())	//找是否有一个不在名单里 
			printf("NA\n");
		else if(mp[a].sex == mp[b].sex)	//判断是否同性 
			printf("Whatever\n");
		else 
			printf("%s\n", panduan(a, b) ? "Yes" : "No");
	}
}

7愤怒的牛

思路：条件筛选下的回溯查找；

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 100000000;

int n, m;
int x[maxn];

bool C(int d)
{
    int last = 0;
    for (int i = 1; i < m; i++){
        int crt = last + 1;
        while (crt < n && x[crt] - x[last] < d){
            crt++;
        }
        if  (crt == n)
            return false;
        last = crt;
    }
    return true;
}

void solve()
{
    //从最开始对x数组排序
    sort(x, x + n);

    //初始化解的存在范围
    int lb = 0, ub = INF;
     
    while (ub - lb > 1){
        int mid = (lb + ub) / 2;
        if (C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", lb);
}

int main()
{
    while (scanf("%d%d", &n, &m) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d", &x[i]);
        }
        solve();
    }
    return 0;
}