#include <stack>
#include <iostream>
using namespace std;

bool isPopOrder(string s1, string s2){
    stack<char> stk;
    int j = 0;
    for(int i = 0; i < s1.size(); i++){
        stk.push(s1[i]);
        if(stk.top() == s2[j]){
            while(!stk.empty() && stk.top() == s2[j]){
                stk.pop();
                j++;
            }
        }
    }
    return stk.empty();
}

int main(){
    string s1 = "12345";
    string s2 = "12354";
    cout << isPopOrder(s1, s2) << endl;
}
