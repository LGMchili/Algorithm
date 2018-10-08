#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache{
public:
    LRUCache(int capacity):_capacity(capacity){};
    int get(int key){
        auto it = _cache.find(key);
        if(it == _cache.end()){
            return -1;
        }
        auto pointer = it->second.second;
        _used.erase(pointer);
        _used.push_front(key);
        it->second.second = _used.begin();
        int value = it->second.first;
        printf("key: %d, value: %d\n", key, value);
        return value;
    }
    void put(int key, int val){
        if(get(key) != -1){
            auto it = _cache.find(key);
            it->second.first = val;
            return;
        }
        if(_cache.size() == _capacity){
            auto pointer = prev(_used.end());
            _cache.erase(*pointer);
            _used.erase(pointer);
            printf("key: %d is evicted\n", *pointer);
        }
        _used.push_front(key);
        _cache[key] = {val, _used.begin()};
    }
private:
    int _capacity;
    list<int> _used;
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
};

int main(){
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
    return 0;
}
