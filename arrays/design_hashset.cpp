class MyHashSet {
public:
// here we just use a vector v ( a direct hash table since each key is
// unique) , we declare it outside the functions in myhashset we 
// initialise it by resizing it , when we add a key we set its value as
// 1 to idcicate its present when its removed we set it to -1 , so when
// we check for a keys presence we check what values stored at that key ,
// ofc there are many limitation like if we remove a element thats not
// present and we can simplify this by initialising the vector elements
// as -1 and we add a key we change the element of that key index to some
// other number so if element is -1 that key  is not present
vector<int>v;
    MyHashSet() {
        v.resize(1000001,0);
    }
    
    void add(int key) {
        v[key]=1;
    }
    
    void remove(int key) {
        v[key]=-1;
    }
    
    bool contains(int key) {
        if(v[key]==1){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */