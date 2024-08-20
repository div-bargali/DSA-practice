class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(1001, 0));

        for (int i = 0; i <= 1000; ++i) dp[n][i] = 1;

        for (int ind = n - 1; ind >= 0; --ind) {
            vector<int> prefix(1001, 0);

            for (int a = 0; a <= 1000; ++a) {
                prefix[a] = dp[ind + 1][a];
                if (a > 0) prefix[a] = (prefix[a] + prefix[a - 1]) % MOD;
            }

            for (int pa = 0; pa <= 1000; ++pa) {
                int ans = 0; 
                int right = nums[ind], left = pa;
                if (ind > 0) {
                    left = max(pa, nums[ind] - nums[ind-1] + pa);
                } 
                if (left <= right) {
                   ans = (prefix[right] - 
                        (left > 0 ? prefix[left-1] : 0) + MOD) % MOD;
                }
                dp[ind][pa] = ans;
            }
        }

        return dp[0][0];
    }
};
