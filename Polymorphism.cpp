#include <iostream>
#include <string>
using namespace std;

class base{
public:
    base(){
        cout << "construction of base" << endl;
    }
    virtual ~base(){
        cout << "destruction of base" << endl;
    }
    virtual void print(){
        cout << "base" << endl;
    }
};

class derive: public base{
public:
    derive(){
        cout << "construction of derive" << endl;
    }
    ~derive(){
        cout << "destruction of derive" << endl;
    }
    virtual void print() {
        cout << "derive" << endl;
    }
};

void foo(base& ob){
    ob.print();
}

int main(){
    base* a = new base();
    derive* b = new derive();
    delete a;
    delete b;
    return 0;
}
