/*
7-5 哈夫曼编码
给定一段文字，如果我们统计出字母出现的频率，是可以根据哈夫曼算法给出一套编码，
使得用此编码压缩原文可以得到最短的编码总长。然而哈夫曼编码并不是唯一的。
例如对字符串"aaaxuaxz"，容易得到字母 'a'、'x'、'u'、'z' 的出现频率对应为 4、2、1、1。
我们可以设计编码 {'a'=0, 'x'=10, 'u'=110, 'z'=111}，也可以用另一套
 {'a'=1, 'x'=01, 'u'=001, 'z'=000}，还可以用 {'a'=0, 'x'=11, 'u'=100, 'z'=101}，
 三套编码都可以把原文压缩到14个字节。但是 {'a'=0, 'x'=01, 'u'=011, 'z'=001} 
 就不是哈夫曼编码，因为用这套编码压缩得到 00001011001001 后，解码的结果不唯一，
 "aaaxuaxz" 和 "aazuaxax" 都可以对应解码的结果。本题就请你判断任一套编码是否哈夫曼编码。
输入格式：
首先第一行给出一个正整数 N（2≤N≤63），随后第二行给出 N 个不重复的字符及其出现频率，格式如下：
c[1] f[1] c[2] f[2] ... c[N] f[N]
其中c[i]是集合{'0' - '9', 'a' - 'z', 'A' - 'Z', '_'}中的字符；f[i]是c[i]的出现频率，
为不超过 1000 的整数。再下一行给出一个正整数 M（≤1000），随后是 M 套待检的编码。
每套编码占 N 行，格式为：c[i] code[i]
其中c[i]是第i个字符；code[i]是不超过63个'0'和'1'的非空字符串。
输出格式：
对每套待检编码，如果是正确的哈夫曼编码，就在一行中输出"Yes"，否则输出"No"。
注意：最优编码并不一定通过哈夫曼算法得到。任何能压缩到最优长度的前缀编码都应被判为正确。
*/






/*
哈夫曼树需要满足以下两个性质:
1.所有的哈夫曼编码的长度唯一。
2.对于任意叶子结点，均不会成为其他字符编码的前缀。

在这道题中，哈夫曼树可以通过最小堆实现。小根堆每次弹出两个值，然后将两个值在插入小根堆中。
此问题中的哈夫曼编码长度用字符串长度乘出现的频率次数得到总长度，
然后与最小堆求出来的哈夫曼编码长度比较进行判断是否为哈夫曼编码。
用strstr函数判断是否为前缀。
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
    int s=0,n,m,x,a[100];
    char ch;
    priority_queue<int,vector<int>,greater<int> > q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch>>x;
        a[i]=x;
        q.push(x);
    }
    while(q.size()!=1){
        int x=q.top();
        q.pop();
        int y=q.top();
        q.pop();
        s+=x+y;
		//s为哈弗曼树带权路径长度和，即所对应哈夫曼编码的长度。 
        q.push(x+y);
    }
    cin>>m;
    while(m--){
        int s1=0;
        string str[100];
        for(int i=0;i<n;i++){
            cin>>ch>>str[i];
            s1+=str[i].size()*a[i];
			//根据字符串长度以及出现的频率求出哈夫曼编码长度。 
        }
        if(s!=s1) cout<<"No"<<endl;
		else{
            int jud=1,flag=0;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    flag=0;
                    int len=str[i].size()>str[j].size()?str[j].size():str[i].size();
                    for(int k=0;k<len;k++)
                        if(str[i][k]!=str[j][k]) flag=1;
                    if(!flag) jud=0;
                }
            }
            if(jud) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}
