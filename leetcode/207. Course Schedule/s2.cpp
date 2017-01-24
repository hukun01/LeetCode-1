class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> out(numCourses);
        vector<int> in(numCourses);
        for (auto p : prerequisites) {
            if (out[p.second].find(p.first) == out[p.second].end()) {
                out[p.second].insert(p.first);
                in[p.first]++;
            }
        }
        queue<int> live;
        for (int i = 0; i < numCourses; ++i) {
            if (in[i] == 0) live.push(i);
        }
        int cnt = 0;
        while (!live.empty()) {
            int n = live.front();
            live.pop();
            ++cnt;
            for (int o : out[n]) {
                --in[o];
                if (in[o] == 0) live.push(o);
            }
        }
        return cnt == numCourses;
    }
};