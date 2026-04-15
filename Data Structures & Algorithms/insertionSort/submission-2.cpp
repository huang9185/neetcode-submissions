// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        if (pairs.size() == 0) return vector<vector<Pair>>{};
        vector<vector<Pair>> res(pairs.size());
        res[0] = pairs;
        for (int i = 1; i < pairs.size(); ++i) {
            for (int j = i; j > 0 && pairs[j].key < pairs[j-1].key; --j) {
                swap(pairs[j], pairs[j-1]);
            }
            res[i] = pairs;
        }
        return res;
    }
};
