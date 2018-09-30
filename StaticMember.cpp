#include <iostream>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <map>
using namespace std;

class foo{
public:
    foo(){
        _i++;
        cout << "foo" << endl;
    }
    ~foo(){
        _i--;
        cout << "-foo" << endl;
    }
    static int getCount(){
        return _i;
    }
private:
    static int _i;
};
int foo::_i = 0;
int main(){
    foo a;
    foo* b= new foo();
    cout << foo::getCount() << endl;
    delete b;
    cout << foo::getCount() << endl;
    return 0;
}
