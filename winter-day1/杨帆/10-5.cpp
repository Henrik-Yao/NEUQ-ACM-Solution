#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<char> left;
    string text;
    while(cin >> text){
    	int lackLeft = 0;
        for(int i=0; i<text.size(); i++){
            if(text[i] == ')'){
                if(left.empty())
                    lackLeft++;
                else{
                    left.pop();
                }
            }
            else if(text[i] == '('){
                left.push(text[i]);
            }
        }
        if(left.empty() && lackLeft == 0){
            cout << "Match" << endl;
        }
        else{
        	cout << lackLeft + left.size() << endl;
            for(int i=1; i<=lackLeft; i++){
                cout << '(';
            }
            cout << text;
            int len = left.size();
            for(int i=1; i<=len; i++){
                cout << ')';
            	left.pop();
            }
            cout << endl;
        }
    }
}
