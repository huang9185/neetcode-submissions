class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // brute force:
        // pick k = highest column
        // h_needed = size of piles
        // try k--;
        // taking piles[i]/k round up
        // add all results together
        // if < h, acceptable, else take last k
        int high = *(max_element(piles.begin(), piles.end())); // always keep high acceptable
        int low = 1; // we dont know if low is acceptable
        while (low < high) {
            int mid = low + (high-low)/2;
            int res = accumulate(piles.begin(), piles.end(), 0, 
                [mid](int sum, int val) {
                    return sum + (val + mid - 1) / mid;
                });
            if (res <= h) {
                // acceptable result
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return high;
    }
};
