class MyHashMap {
    set<pair<int, int>> s;
    set<int> keys;
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        pair<int, int> p;
        p.first = key;
        p.second = value;
        
        auto x = keys.insert(key);
        if (!x.second) {
            remove(key);
        }
        s.insert(p);
    }
    
    int get(int key) {
        for (auto elem : s) {
            if (elem.first == key) {
                return elem.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        pair<int, int> temp;
        for (auto elem : s) {
            if (elem.first == key) {
                temp = elem;
            }
        } 
        s.erase(temp);
    }
};