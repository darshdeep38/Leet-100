class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0 ;
        for(int i = 0 ; i < nums.size(); i++){

        // If current index is beyond the farthest reachable point
        if( i> maxReach) return false;

        // Update farthest reachable index
        maxReach = max(maxReach  ,  i + nums[i]);

        // Early stopping: already can reach or exceed last index
        if(maxReach >= nums.size() -1 ) return true ;


        }

        return true;
    }
};
