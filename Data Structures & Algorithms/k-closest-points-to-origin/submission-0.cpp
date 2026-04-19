class Solution {
    struct Logic {
        auto operator()(const vector<int>& left, const vector<int>& right) {
            return pow(left[0], 2.0)+pow(left[1], 2.0) < 
                pow(right[0], 2.0)+pow(right[1], 2.0);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Logic> pq;
        int i = 0;
        while (i < k) {
            pq.push(points[i]);
            ++i;
        }
        while (i < points.size()) {
            if (pow(pq.top()[0],2.0)+pow(pq.top()[1],2.0) >
                pow(points[i][0],2.0)+pow(points[i][1],2.0))
                {
                    pq.pop();
                    pq.push(points[i]);
                }
            ++i;
        }
        vector<vector<int>> res;
        res.reserve(pq.size());
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};
