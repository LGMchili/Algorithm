#include <iostream>

using namespace std;

class foo
{
public:
    foo() {};
    ~foo() { cout << "destruction" << endl; };
    int val = 0;
};

void fun(shared_ptr<foo> ptr_1){
    shared_ptr<foo> ptr_2 = ptr_1;
    cout << "ptr_2 deleted" << endl;
}

int main()
{
    foo* a = new foo();
    shared_ptr<foo> ptr_1(a);
    fun(ptr_1);
    cout << "ptr_1 deleted" << endl;
    cout << 1/2 << endl;
    return 0;
}
