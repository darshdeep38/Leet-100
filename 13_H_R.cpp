class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for (int money : nums) {
            int pick = prev2 + money;
            int skip = prev1;
            int curr = max(pick, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
