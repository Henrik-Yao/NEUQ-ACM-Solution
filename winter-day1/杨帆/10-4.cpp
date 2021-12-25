#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];
vector <int> odd;
vector <int> even;

struct Node{
    int data;
    Node *next;
};

int main(){
    int num = 0,t1 = 0, t2 = 0;
    while(cin >> a[num++]);
    num--;
    sort(a,a+num);
    for(int i=0; i<num; i++){
        if(i > 0){
            cout << "->";
        }
        cout << a[i];
    }
    cout << endl;
    for(int i=0; i<num; i++){
        if(a[i] & 1){
            odd.push_back(a[i]);
        }
        else{
            even.push_back(a[i]);
        }
    }
    for(int i=0; i<odd.size(); i++){
        if(i > 0){
            cout << "->";
        }
        cout << odd[i];
    }
    cout << endl;
    for(int i=0; i<even.size(); i++){
        if(i > 0){
            cout << "->";
        }
        cout << even[i];
    }
}
