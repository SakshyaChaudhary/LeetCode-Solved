class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;
        for(int i=0;i<nums.size();i++){
            // Check if current index is reachable
            if(i>maxReach){
                return false;
            }
            //Update max
            maxReach=max(maxReach,i+nums[i]);
            // can reach the last index
            if(maxReach>=nums.size()-1){
                return true;
            }
        }
        return true;        
    }
};