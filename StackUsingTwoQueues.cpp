#include <queue>
#include <iostream>
using namespace std;
template<typename T>
class myStackPop{
public:
    myStackPop(){
        _q1 = new queue<T>;
        _q2 = new queue<T>;
    }
    ~myStackPop(){
        delete _q1;
        delete _q2;
    }
    void push(T val){
        _q1->push(val);
        while(!_q2->empty()){
            _q1->push(_q2->front());
            _q2->pop();
        }
        swap(_q1, _q2);
    }
    void pop(){
        if(!_q2->empty())
            _q2->pop();
    }
    T top(){
        return _q2->front();
    }
    bool empty(){
        return _q2->size() == 0; // data stored in q2, already in forms of a stack
    }
private:
    queue<T>* _q1, *_q2;
};

template<typename T>
class myStackPush{
public:
    myStackPush(){
        _q1 = new queue<T>;
        _q2 = new queue<T>;
    }
    ~myStackPush(){
        delete _q1;
        delete _q2;
    }
    void push(T val){
        _q1->push(val);
    }
    void pop(){
        if(_q1->empty())
            return;
        while(_q1->size() > 1){
            _q2->push(_q1->front());
            _q1->pop();
        }
        _q1->pop();
        swap(_q1, _q2);
    }
    T top(){
        T res;
        while(!_q1->empty()){
            res = _q1->front();
            _q2->push(res);
            _q1->pop();
        }
        swap(_q1, _q2);
        return res;
    }
    bool empty(){
        return _q1->size() == 0; // data stored in q1, as a queue
    }
private:
    queue<T>* _q1, *_q2;
};

int main(){
    myStackPop<int> stk;
    for(int i = 10; i > 0; i--){
        stk.push(i);
    }
    while(!stk.empty()){
        cout << stk.top() << endl;
        stk.pop();
    }
}
