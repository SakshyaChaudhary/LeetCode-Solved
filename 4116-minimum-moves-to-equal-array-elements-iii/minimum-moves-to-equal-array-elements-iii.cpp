class Solution {
public:
    int minMoves(vector<int>& nums) {
        //2 Pass Approach
        //Find Max then difference of ans+=element with Max 

        //Single Pass- Rectangle Approach
        int maxi=nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int totalArea=nums.size() * maxi;
        return totalArea-sum;
    }
};