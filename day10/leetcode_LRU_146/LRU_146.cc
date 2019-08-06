#include <iostream>
#include <unordered_map>
#include <list>
using std::unordered_map;
using std::list;
using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
class LRUCache {
public:
    LRUCache(int capacity)
    :_capicity(capacity)
    {}
    int get(int key)
    {
        auto iterator=_m.find(key);
        if(iterator==_m.end())
            return -1;
        int val=iterator->second->second;
        _list.erase(iterator->second);
        _list.push_front(make_pair(key,val));
        _m[key]=_list.begin();
        cout<<key<<"'s value="<<val<<endl;
        return iterator->second->second;
    }
    void put(int key, int value)
    {
        cout<<"put key="<<key<<", value="<<value<<endl;
        auto iterator=_m.find(key);
        if(iterator!=_m.end())
            _list.erase(iterator->second);
        _list.push_front(make_pair(key,value));
        _m[key]=_list.begin();
        if(_list.size()>_capicity){
            int key=_list.back().first;
            _m.erase(key);
            _list.pop_back();
        }
    }
private:
    int _capicity;
    list<pair<int,int>> _list;
    unordered_map<int,list<pair<int,int>>::iterator> _m;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
}