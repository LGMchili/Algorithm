#include <iostream>
#include <vector>
#include <limits>
using namespace std;
template<typename T>
class myPriorityQueue{
public:
    myPriorityQueue():_size(0){};

    void build(){
        // make sure evey subtree is max heap
        for(int i = _size; i > 0; i--){
            heapify(_queue, i);
        }
    }

    void heapify(int i){
        int l = 2*i; // left
        int r = l + 1; // right
        int largest = i;
        if(l <= _size && _queue[i-1] < _queue[l-1])
            largest = l;
        if(r <= _size && _queue[largest-1] < _queue[r-1])
            largest = r;
        if(largest != i){
            swap(_queue[i-1], _queue[largest-1]);
            heapify(largest); // heapify the child tree
        }
    }

    void increase(T val, int i){
        // if(_queue[i-1] > val)
        //     throw runtime_error("new key is smaller than the old one");
        _queue[i-1] = val;
        while(i > 1 && (_queue[i-1] > _queue[i / 2 - 1])){
            swap(_queue[i-1], _queue[i / 2 - 1]);
            i = i / 2;
        }
        // cout << "current top: " << _queue[0] << endl;
    }

    void insert(T val){
        // cout << "insert: " << val << ", ";
        _queue.push_back(INT_MIN);
        _size++;
        increase(val, _size);
    }

    T top(){
        return _queue[0];
    }

    void pop(){
        _queue[0] = _queue[_size-1];
        _queue.pop_back();
        _size--;
        heapify(1);
    }

    int size(){
        return _size;
    }

    bool empty(){
        return _size == 0;
    }
private:
    vector<T> _queue;
    int _size;
};

int main(){
    myPriorityQueue<int> pq;
    pq.insert(3);
    pq.insert(5);
    pq.insert(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.insert(8);
    cout << pq.top() << endl;
    cout << "size of pq: " << pq.size() << endl;
    pq.insert(-1);
    pq.insert(0);
    pq.insert(12);
    pq.insert(-13);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
