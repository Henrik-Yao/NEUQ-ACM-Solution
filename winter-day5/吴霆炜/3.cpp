#include <bits/stdc++.h>
using namespace std;

list<int>l1,l2;
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int data;
        scanf("%d",&data);
        l1.push_back(data);
    }
    for(int i = 0;i < n;i++){
        int data;
        scanf("%d",&data);
        l2.push_back(data);
    }
    l1.sort();l2.sort();
    l1.merge(l2);
    int sz = l1.size();
    int i = (sz + 1) / 2 - 1;
    list<int>::iterator it = l1.begin();
    while(i--) it++;
    printf("%d\n",*it);
    return 0;
}