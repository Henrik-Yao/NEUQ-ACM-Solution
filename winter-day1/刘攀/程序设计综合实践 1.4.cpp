#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
list<int>l1,l2,l3;
int main(){
    int num;
    while(cin>>num) v.push_back(num);
    sort(v.begin(),v.end());
    if(!v.empty()){
    printf("%d",v[0]);
    for(int i = 1;i < v.size();i++)printf("->%d",v[i]);
    }
    puts("");
    for(int i = 0;i < v.size();i++)l1.push_back(v[i]);
    for(list<int>::iterator i = l1.begin();i != l1.end();i++){
        if(*i%2==1) l2.push_back(*i);
        else l3.push_back(*i);
    }
    vector<int>v1(l2.begin(),l2.end()),
	v2(l3.begin(),l3.end());
    if(!v1.empty()){
    printf("%d",v1[0]);
    for(int i = 1;i < v1.size();i++) printf("->%d",v1[i]);
    }
    puts("");
    if(!v2.empty()){
    printf("%d",v2[0]);
    for(int i = 1;i < v2.size();i++) printf("->%d",v2[i]);
    }
    l1.clear();l2.clear();l3.clear();v1.clear();v2.clear();
    return 0;
}

