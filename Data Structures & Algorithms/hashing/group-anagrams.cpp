class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string& word : strs) {
            string tsort = word;
            sort(tsort.begin(), tsort.end());
            map[tsort].push_back(move(word));
        }

        vector<vector<string>> res;
        res.reserve(map.size());
        for (auto& [k,v]:map) {
            res.push_back(move(v));
        }
        return res;
    }
};

