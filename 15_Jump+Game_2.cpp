class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0 ; // total number of jumps taken 
        int currEnd =0;  // end of the current jump range
        int curFarthest = 0 ; //farthest point reachable in this range 


                // We stop at n-2 because when we reach last index, no jump is needed
                for(int i = 0 ; i<n-1 ; i++){
                // Update the farthest we can reach from current window
                curFarthest = max(curFarthest , i + nums[i]);


            // When we've explored all positions in current jump's range,
            // we must take another jump


            if(i == currEnd){

                jumps++;
                 currEnd = curFarthest ;
                 // if we already can reach end, no need to continue
                if(currEnd >= n -1 ) break;
            }

                }
                return jumps ;


    }
};
