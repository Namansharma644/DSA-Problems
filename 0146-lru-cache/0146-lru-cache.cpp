class LRUCache {
public:
    list<int> dll;
    int n;
    unordered_map<int,pair<int,list<int>::iterator>>m;

    LRUCache(int capacity) {
        n=capacity;
    }
    
    void  makeRecentlyUsed(int key)
    {
         dll.erase(m[key].second);
         dll.push_front(key);
         m[key].second=dll.begin();
    }

    int get(int key) {
        if(m.find(key)==m.end())
        {
            return -1;
        }

        int val=m[key].first;

        makeRecentlyUsed(key);
        return val;
    }
    
    void put(int key, int value) {
       if(m.find(key)!=m.end())
       {
          m[key].first=value;
          makeRecentlyUsed(key);
          return;
       }
       else
       {
          dll.push_front(key);
          m[key]={value,dll.begin()};
          n--;
       }

       if(n<0)
       {
          int keyToDelete=dll.back();
          m.erase(keyToDelete);
          dll.pop_back();
          n++;
       }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */