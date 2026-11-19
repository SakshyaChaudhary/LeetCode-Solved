class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxDist=0;
        for(int i=0;i<nums.size();i++){
            maxDist=max(maxDist,i+nums[i]);
            if(maxDist>=nums.size()-1){
                return true;
            }
            if(maxDist<=i){
                return false;
            }
        }
        return true;
    }
};