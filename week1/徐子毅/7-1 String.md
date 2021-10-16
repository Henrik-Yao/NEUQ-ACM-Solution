# 7-1 String

> 给定一个只含有小写字母的文本串，给定*n*个模式串，求每个模式串在文本串中的出现次数。

我的做法是比较两个string：**str**和**strr**。 *str是文本串，而strr是模式串* 。以strr的第一个字符作为标志，在str中找到strr的第一个字符，再分别比较str和strr的每一个字母，匹配上即sum++。

```C++
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int N,flag;
    string str,sstr;
    cin >> N;
    cin >> str;//读入文本串
    for(int T=1;T<=N;T++){
        cin >> sstr;//读入模式串
        int num=0;
        if(sstr.size()>str.size()){
        	cout << 0 << endl;continue;
		}
        for(int i=0;i<=str.size()-sstr.size();i++){
            if(str[i]==sstr[0]){//寻找str中与strr匹配的第一个字符
                flag=1;
                int ip=i;
                for(int p=0;p<sstr.size()&&ip<str.size();p++,ip++) if(str[ip]!=sstr[p]) flag=0;//分别匹配每一个字符
                if(flag==1) {//如果全匹配
                	num++;
				}
            }
        }
        cout << num << endl;
    }
    return 0;
}
```

