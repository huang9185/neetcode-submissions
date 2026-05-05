class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // keep a deque, strictly descending order
        // first we insert k elements into deque
        deque<int> q;
        for (int i = 0; i < nums.size() && i < k; ++i) {
            addDeque(q, nums, i);
        }
        vector<int> output;
        output.reserve(nums.size()-k+1);
        output.push_back(nums[q.front()]);
        // then we iterate: kick the old one out if exists, add the new one in
        for (int i = k; i < nums.size(); ++i) {
            if (q.front() == i-k) q.pop_front();
            addDeque(q, nums, i);
            output.push_back(nums[q.front()]);
        }
        return output;
    }
    void addDeque(deque<int>& q, vector<int>&nums, int index) {
        int val = nums[index];
        while (!q.empty() && nums[q.back()] <= val) {
            q.pop_back();
        }
        q.push_back(index);
    }
};

