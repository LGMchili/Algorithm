#include <iostream>
using namespace std;

template<typename T>
class sp{
public:
    sp(T* ptr):_pointer(ptr){}
    ~sp(){ delete _pointer; }
    T* operator->(){
        return _pointer;
    }
    T& operator*(){
        return *_pointer;
    }
private:
    T* _pointer;
};

class myclass{
public:
    ~myclass(){ cout << "destruction" << endl; }
    void display(){
        cout << "display" << endl;
    }
};

int main(){
    myclass* a = new myclass();
    sp<myclass> ptr(a); // initialize a smart pointer
    myclass b = *ptr; // a copy is made
    a->display();
    b.display();
    return 0;
}
