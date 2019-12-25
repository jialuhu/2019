/*************************************************************************
	> File Name: LRU缓存机制.cpp
	> Author: 
	> Mail: 
	> Created Time: 三 12/25 17:06:09 2019
 ************************************************************************/


/**
 
 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 
 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
 
 进阶:
 
 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 
 示例:
 
 LRUCache cache = new LRUCache( 2 // 缓存容量 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        //哈希查找，查找到了的话，就把该节点移动到list的头部，没有返回-1
        auto it = map_.find(key);
        if(it==map_.end()) return -1;
        else{
            int value = it->second->second;
            list_.erase(it->second);
            list_.push_front(make_pair(key,value));
            map_[key] = list_.begin();
            return value;
        }
    }
    //首先看key值是否存在，若存在，需要删除该节点，再将该节点移动到list的首部
    //若不存在，插入新的节点
    //若插入后长度超出之前的长度，那么就将最后一个key-value节点删除
    void put(int key, int value) {
        auto it = map_.find(key);
        if(it != map_.end()){
            list_.erase(it->second);
        }
        list_.push_front(make_pair(key,value));
        map_[key] = list_.begin();
        if(list_.size() > capacity_){
            int key = list_.back().first;
            map_.erase(key);
            list_.pop_back();
        }
    }
private:
    int capacity_;
    list<pair<int, int>> list_;
    unordered_map<int, list<pair<int,int>>::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
