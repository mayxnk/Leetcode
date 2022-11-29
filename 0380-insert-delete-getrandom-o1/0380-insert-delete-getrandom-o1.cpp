class RandomizedSet {
public:
    RandomizedSet() : seed((random_device())()) {}

    bool insert(int val) {
        if (lookup.count(val)) return false;
        lookup[val] = values.size();
        values.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!lookup.count(val)) return false;
        
        // copy the last value in the array
        // to the current location of the value
        // we want to remove
        values[lookup[val]] = values.back();
        
        // set the location of the last value
        // in the array to the current location
        lookup[values.back()] = lookup[val];
        
        // remove the current element
        values.pop_back();
        lookup.erase(val);

        return true;
    }
    
    int getRandom() {
        return values[uniform_int_distribution<>
                        (0, values.size() - 1)(seed)];
    }
private:
    unordered_map<int, int> lookup;
    vector<int> values;
    default_random_engine seed;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */