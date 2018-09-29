#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class myQueue{
public:
    void push(T val){
        _inBox.push(val);
    }

    void pop(){
        if(_outBox.empty())
            toOutBox();
        _outBox.pop();
    }

    T top(){
        if(_outBox.empty())
            toOutBox();
        return _outBox.top();
    }
private:
    void toOutBox(){
        if(_inBox.empty())
            throw runtime_error("Read from empty queue");
        while(!_inBox.empty()){
            _outBox.push(_inBox.top());
            _inBox.pop();
        }
    }
    stack<T> _inBox, _outBox;
};

int main(){
    myQueue<int> q;
    q.push(2);
    q.push(1);
    q.push(4);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    return 0;
}
