#include <condition_variable>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
class semaphore{
public:
    semaphore(int count = 0):_count(count){};
    void post(){
        {
            unique_lock<mutex> lock(_mtx);
            _count++;
        }
        _cv.notify_one();
    }
    void wait(){
        unique_lock<mutex> lock(_mtx);
        _cv.wait(lock, [this](){ return _count > 0; });
        _count--;
    }
private:
    int _count;
    mutex _mtx;
    condition_variable _cv;
};

semaphore empty(3);
semaphore full(0);
mutex mtx;
void producer(){
    int i = 1;
    while(true){
        empty.wait();
        {
            lock_guard<mutex> lock(mtx);
            this_thread::sleep_for(std::chrono::seconds(1));
            cout << "product produced " + to_string(i) << endl;
        }
        full.post();
        i++;
    }
}
void consumer(){
    int i = 1;
    while(true){
        full.wait();
        {
            lock_guard<mutex> lock(mtx);
            this_thread::sleep_for(std::chrono::seconds(1));
            cout << "product consumed " + to_string(i++) << endl;
        }
        empty.post();
    }
}
int main(){
    thread csr(&consumer);
    thread prd(&producer);
    csr.join();
    prd.join();
    return 0;
}
