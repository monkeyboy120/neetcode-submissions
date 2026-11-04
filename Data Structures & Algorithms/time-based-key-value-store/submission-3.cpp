class TimeMap {
   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& values = keyStore[key]; // values = vector of timestamp + key
        int l = 0; 
        int r = values.size() - 1;
        string res = "";

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(values[mid].first <= timestamp) {
                res = values[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

   private:
    unordered_map<string, vector<pair<int, string>>> keyStore;
};
