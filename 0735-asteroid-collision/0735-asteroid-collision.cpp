class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int a : asteroids) {
            if (s.empty() || a > 0 || s.top() < 0) {
                s.push(a);
            } else {
                while (!s.empty() && s.top() > 0 && s.top() < abs(a)) {
                    s.pop();
                }
                if (s.empty() || s.top() < 0) {
                    s.push(a);
                } else if (s.top() == abs(a)) {
                    s.pop();
                }
            }
        }
        
        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};
