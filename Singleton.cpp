#include <iostream>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <map>
using namespace std;

template<typename T>
class S{
public:
    static T& getInstance()
    {
        static T _instance;
        return _instance;
    }

private:
    S(){};                    // Constructor? (the {} brackets) are needed here.
    S(S const&);              // Don't Implement
    void operator=(S const&); // Don't implement
};
// Instantiated on first use.
// template<typename T>
// T* S<T>::_instance = new T();
int main(){
    int *a = &S<int>::getInstance();
    (*a)++;
    int *b = &S<int>::getInstance();
    cout << *a << endl;
    cout << b << endl;
    return 0;
}
