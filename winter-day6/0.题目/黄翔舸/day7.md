​                                                                        day7

1.

思路：

排序的队列，每次都要输出排序的过程。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100010];
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                j--;

            }
            for (int i = 0; i < n; i++) {
                if (i != 0)cout << " ";
                cout << a[i];
            }
            cout << endl;
        }
    }
    return 0;
}

成绩排序

思路：map构建特殊数组，但是注意输出时同分的会有问题。所以可以用结构体替代map。

#include<iostream>
#include<cstring>
using namespace std;
#define size 21
struct student
{
    char name[size];
    int score;
};
int main()
{
    struct student s[size],temp;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>s[i].name>>s[i].score;
    
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(s[j].score<s[j+1].score){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
            if(s[j].score==s[j+1].score && strcmp(s[j].name,s[j+1].name)>0){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    { cout<<s[i].name<<" "<<s[i].score;
     if(i!=n-1)
     {
         cout<<endl;
     }
    }
    
    return 0;
}

统计工龄

思路：简单的排序。

#include<iostream>
using namespace std;
int age[51];
int main(){
 int n;
int a;
    int i=0;
 cin>>n;
 while(n--){
  cin>>a;
  age[a]++;
 }
 for(;i<=50;i++)
  if(!age[i])
   continue;
  else
   cout<<i<<":"<<age[i]<<endl;
 return 0;
}

4 最接近神的人

思路：用vector排序容器，注意条件判断（逻辑还挺复杂的）

#include<algorithm>
#include<iostream>

 #include<cstring> 
#include<cstdio>
 #include<cmath>
 #include<vector>
 using namespace std;
 const int mxn = 500010;
 int read() {
	     int x = 0, f = 1; char ch = getchar();
   while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
	    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	   return x * f;
	
}
 int t[mxn], a[mxn];
 int n;
  long long ans = 0;
void merge(int l, int r) {
	    if (l >= r)return;
	    int mid = (l + r) >> 1;
	    merge(l, mid);
	    merge(mid + 1, r);
	    int p = l, q = mid + 1, i = l;
	    while (p <= mid || q <= r) {
		       if (q > r || (p <= mid && a[p] <= a[q])) {
			            t[i++] = a[p++];
			
		}
		         else t[i++] = a[q++], ans += mid - p + 1;
		
	}
	     for (i = l; i <= r; i++)a[i] = t[i];
	    return;

}
 int main() {
	     n = read();
	    int i, j;
	    for (i = 1; i <= n; i++)
		       a[i] = read();
	    merge(1, n);
	   printf("%lld\n", ans);
	    return 0;
	
}