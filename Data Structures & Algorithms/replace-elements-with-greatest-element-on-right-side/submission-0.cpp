class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // from right to left with i
        // max is the max[i+1, n]
        // copy that max
        // use cur to compute new max[i,n]
        // cur takes copy[i+1,n]

        int max = 0;
        int toPlace = -1;
        for (int i = size(arr)-1; i >= 0; --i) {
            if (arr[i] > max) max = arr[i];
            arr[i] = toPlace;
            toPlace = max;
        }
        return arr;
    }
};