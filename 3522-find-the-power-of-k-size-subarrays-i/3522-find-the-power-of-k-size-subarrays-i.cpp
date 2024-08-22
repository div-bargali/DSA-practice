class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i <= n-k; i++) {
            int prev = nums[i];
            bool flag = true;
            for (int j = i+1; j < i+k; j++) {
                if (prev+1 != nums[j]) {
                    flag = false; break;
                } 
                prev = nums[j];
            }
            if (!flag) ans.push_back(-1);
            else ans.push_back(nums[i+k-1]);
        }
        return ans;
    }
};