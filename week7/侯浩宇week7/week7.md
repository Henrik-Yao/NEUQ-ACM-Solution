### **7-1 词典**

记录每个词的意思，一一比对，时间复杂度为O(mn)。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    string a[10001],b[10001],c[10001];
    cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
	for(int i=0;i<m;i++){
		cin>>c[i];int p=1;
		for(int j=0;j<n;j++){
			if(c[i]==b[j]){cout<<a[j]<<endl;p=0;break;}
		}
		if(p) cout<<"eh"<<endl;
	}
	return 0;
}
```

### **7-2 神秘密码**

递归思想，每遇到‘【’时递归。

```c++
#include <bits/stdc++.h>
using namespace std;
string dg(){
    string a,b;
    int n;
    char c;
    while(cin>>c){
        if(c=='['){
            cin>>n;
            b=dg();
            for(int i=0;i<n;i++)
			a+=b;
        } 
		else{
            if(c==']')return a;
            else a+=c;
        }
    }
}
int main(){
	string ans=dg();
    cout<<ans;
    return 0;
}
```

### **7-3 删除公共字符**

标记第二个字符串，输出第一个字符串中未标记的字符。（ps：输入时要用while（getline（a）&&getline（b))，不然会把第二个字符串当做第二次计算的第一个字符串）

```c++
#include<bits/stdc++.h>
using namespace std;
int m=0;
int ss(){
		 
		string a[10000],b[10000];
		bool p[10000];
		memset(p,1,10000);
		if(getline(cin,a[m])&&getline(cin,b[m])){
//		cin>>b[m];
		for(int i=0;i<b[m].length();i++)
		if(p[int(b[m][i])]) p[int(b[m][i])]=0;
		if(m)cout<<endl;
		m++;
//		if(m%2==1)
		for(int i=0;a[m-1][i];i++)
		if(p[int(a[m-1][i])])cout<<a[m-1][i];	
		
		return 1;		
		}
		else return 0;	
}
int main(){
	while(ss()){
	}
	return 0;
}
```

### **7-4 最长有序子序列**

用动态规划记录大小，并实时刷新（ps：我因为这个错了好久）

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int dp[100000],t,a[100000],n,maxx;
	cin>>t;
	while(t--){
		maxx=0;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i],dp[i]=1;
	    for(int i=0;i<n;i++){
		    for(int j=i;j>=0;j--)
				if(a[i]>a[j]){dp[i]=max(dp[i],dp[j]+1);}
			if(maxx<dp[i]) maxx=dp[i];
	    }
	    cout<<maxx<<endl;
	    if(t)cout<<endl;
	}
	return 0;
}
```

### **7-5 0-1背包问题**

动态规划思想。（ps:注意审题，是先输入n个w【i】，再输入n个v【i】，而不是n个w【i】，v【i】）

```c++
#include <bits/stdc++.h>
using namespace std;
int n,c,maxx;
int w[405],v[405];
int dp[1505];
void bb(){
	maxx = 0;
	for (int i = 1;i <= n; i++)
		cin>>w[i];
	for (int i = 1;i <= n; i++)
		cin>>v[i];
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	for (int i=1;i<=n;i++)
	for (int j=c;j>=w[i];j--)
		dp[j]=max(dp[j],dp[j-w[i]]+v[i]);		
	for (int i=1;i<=c;i++)
		maxx=max(maxx,dp[i]);
	cout<<maxx<<endl;
}
int main(){
	while (cin>>n>>c){
		bb();
	}
	return 0;
}
```

