#include<bits/stdc++.h>
using namespace std;

bool is(char ch){
	if(ch != '{' && ch != '}' && ch != '[' && ch != ']' && ch != '(' && ch != ')'){
		return true;
	}
	else{
		return false;
	}
}
int main(){
    queue<char> SmallLeft;
    queue<char> MidLeft;
    queue<char> LargeLeft;
    string text;
    bool flag = 0;
    cin >> text;
    for(int i=0; i<text.size(); i++){
        if(is(text[i]))     continue;
        else if(text[i] == '('){
            SmallLeft.push(text[i]);
        }
        else if(text[i] == ')'){
            if(SmallLeft.empty()){
                flag = 1;
                break;
            }
            else{
                SmallLeft.pop();
            }
        }
        else if(text[i] == '['){
            MidLeft.push(text[i]);
        }
        else if(text[i] == ']'){
            if(MidLeft.empty()){
                flag = 1;
                break;
            }
            else{
                MidLeft.pop();
            }
        }
        else if(text[i] == '{'){
            LargeLeft.push(text[i]);
        }
        else if(text[i] == '}'){
            if(LargeLeft.empty()){
                flag = 1;
                break;
            }
            else{
                LargeLeft.pop();
            }
        }
    }
    if(SmallLeft.size() || MidLeft.size() || LargeLeft.size()){
        flag = 1;
    }
    if(flag){
        cout << "no";
    }
    else{
        cout << "yes";
    }
}
