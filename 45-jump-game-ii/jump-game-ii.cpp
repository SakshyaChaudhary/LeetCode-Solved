class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int left=0,right=0;
        while(right<nums.size()-1){
            int farest=0;
            for(int i=left;i<=right;i++){
                farest=max(farest,i+nums[i]);
            }
            left=right+1;
            right=farest;
            jump++;
        }
        return jump;
    }
};