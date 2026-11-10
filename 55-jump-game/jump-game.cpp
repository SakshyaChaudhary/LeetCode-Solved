class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0]==0) return false;
        int maxReach=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && maxReach==i && i!=nums.size()-1){
                return false;
            }
            maxReach=max(maxReach,nums[i]+i);
        }
        return true;
        
    }
};