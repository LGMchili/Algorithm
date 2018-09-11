#include <iostream>

using namespace std;

class base{
public:
    virtual void print(){
        cout << "base" << endl;
    }
};

class derive: public base{
    void print() {
        cout << "derive" << endl;
    }
};

void foo(base& ob){
    ob.print();
}

int main(){
    base a;
    derive b;
    cout << "base class output: ";
    foo(a);
    cout << "derive class output: ";
    foo(b);
    return 0;
}
