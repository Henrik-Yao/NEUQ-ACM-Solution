/*
 * @Author: ComplexPug
 * @Email: 3010651817@qq.com
 * @Date: 2021-12-25 08:11:13
 * @LastEditTime: 2021-12-25 08:12:24
 */
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
struct node {
    node(char x=0,int y=0,int z=0):s(x),nxt(y),pre(z){}
    char s;
    int nxt,pre;
}a[_];
int main() {
    // freopen("a.in","r",stdin);
    char s;
    int E=0,now=0,flag=0,tmp=0;
    while((s=getchar())!=EOF) {
        // cout<<":::"<<s<<"\n";
        if((s>='a'&&s<='z')||(s==' ')) {
            if(a[now].nxt) {
                if(flag==1) {
                    a[a[now].nxt].s=s;
                    now=a[now].nxt;
                } else {
                    ++tmp;
                    a[tmp]=node(s,a[now].nxt,now);
                    a[now].nxt=tmp;
                    a[a[tmp].nxt].pre=tmp;
                    now=tmp;
                }
            } else {
                ++tmp;
                // cout<<tmp<<"!\n";
                a[tmp]=node(s,0,now);
                a[now].nxt=tmp;
                // printf("a[%d]=node(%c,%d,%d)\n",now,a[now].s,a[now].nxt,a[now].pre);
                now=tmp; 
            }
            if(a[now].nxt==0) E=now;
        } else {
            if(s=='[') {//home
                now=0;
            }
            if(s==']') {//end
                now=E;
            }
            if(s=='{') {//<-                
                now=a[now].pre;
            }
            if(s=='}') {//->
                if(a[now].nxt) now=a[now].nxt;
            }
            if(s=='-') {//insert
                flag^=1;
            }
            if(s=='=') {//backspace
                if(!now) continue;
                a[a[now].pre].nxt=a[now].nxt;
                if(a[now].nxt) a[a[now].nxt].pre=a[now].pre;
                now=a[now].pre;
            }
        }
    }
    for(now=a[0].nxt;now;now=a[now].nxt) {
        cout<<a[now].s;
        // printf("a[%d]=node(%c,%d,%d)\n",now,a[now].s,a[now].nxt,a[now].pre);
    }
    return 0;
}