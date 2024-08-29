class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '0') cnt++;
                int cnt1 = (j-i+1) - cnt;
                if (cnt1 <= k || cnt <= k) ans++;
            }
        }
        return ans;
    }
};