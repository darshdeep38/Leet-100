class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);

        dp[0] = 0; // 0 coins needed to make amount 0

        for (int coin : coins) {
            for (int a = coin; a <= amount; a++) {
                dp[a] = min(dp[a], dp[a - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
