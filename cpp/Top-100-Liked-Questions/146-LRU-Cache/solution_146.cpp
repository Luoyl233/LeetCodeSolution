/*
 * 146. LRU Cache
 */


#include "common.h"


#if LEET_CODE == 146

class LRUCache {
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            V par = cache[key];
            keys.erase(par.second);
            par.second = keys.insert(keys.end(), key);
            cache[key] = par;
            return par.first;
        }
        else
            return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            V par = cache[key];
            keys.erase(par.second);
            par.second = keys.insert(keys.end(), key);
            par.first = value;
            cache[key] = par;
        }
        else if (cache.size() == this->capacity) {
            int oldKey = keys.front();
            V par = cache[oldKey];
            keys.erase(par.second);
            par.second = keys.insert(keys.end(), key);
            par.first = value;
            cache[key] = par;
            cache.erase(oldKey);
        } else {
            list<int>::iterator iter = keys.insert(keys.end(), key);
            V par = make_pair(value, iter);
            cache[key] = par;
        }
    }

    typedef int K;
    typedef pair<int,list<int>::iterator> V;

    int capacity;
    list<K> keys;
    unordered_map<K, V> cache;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    cout << "146. LRU Cache" << endl;

    return 0;
}


#endif
