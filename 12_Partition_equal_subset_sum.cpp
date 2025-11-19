class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum = 0 ;
       for(int x : nums) sum +=x;
       if(sum % 2 !=  0) return false;

       int target = sum / 2;

    // dp[j] = true means subset with sum j is possible
    vector<bool> dp(target + 1 , false);
    dp[0] = true;

    for(int num :nums ){
    // Traverse backwards to avoid reusing the same number
    for(int j = target ; j >= num ; j--){
        if(dp[j-num])
            dp[j] = true;
    }

    }

    return dp[target];

    }
};
