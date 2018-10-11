#include <stack>
#include <iostream>

using namespace std;

class stackWithMin{
public:
    void push(int val){
        if(s2.empty() || val < s2.top())
            s2.push(val);
        s1.push(val);
    }
    void pop(){
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int min(){
        return s2.top();
    }
private:
    stack<int> s1, s2;
};

int main(){
    stackWithMin stk;
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(1);
    stk.push(2);
    for(int i = 0; i < 5; i++){
        cout << stk.min() << endl;
        stk.pop();
    }
}
