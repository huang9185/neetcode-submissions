class Solution {
    // Kahn's Algo: find nodes with in-deg = 0, take those courses, and continue
public:
// note two locals are keeping different things
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // [prereq]: [courses_following]
        vector<vector<int>> adj(numCourses, vector<int>{});
        // list of courses with no prereq
        vector<int> nprereq(numCourses, 0);
        // queue
        queue<int> q;
        for (const auto& v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            nprereq[v[0]]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (nprereq[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            // take the course
            q.pop();
            ++count;
            vector<int>& courses_following = adj[course];
            for (int c : courses_following) {
                if (--nprereq[c] == 0) q.push(c);
            }
        }
        return count == numCourses;
    }
};

