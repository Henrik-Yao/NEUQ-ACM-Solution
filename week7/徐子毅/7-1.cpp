#include <iostream>
#include <cstring>
using namespace std;
struct dictory{
    string ori;
    string hon;
};
int main(){
    int n,m;
    cin >> n >> m;
    dictory dic[n];
    for(int i=0;i<n;i++){
        cin >> dic[i].ori >> dic[i].hon;
    }
    string honlan;
    for(int abc=0;abc<m;abc++){
        bool found=false;
        cin >> honlan;
        for(int i=0;i<n;i++){
            if(dic[i].hon==honlan) {cout << dic[i].ori << endl;found=true;break;}
        }
        if(!found) cout << "eh" << endl;
    }
    return 0;
}