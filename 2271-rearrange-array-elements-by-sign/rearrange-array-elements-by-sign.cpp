class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums){
        vector<int> ans(nums.size());
        int pos=0;
        int neg=1;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(curr>0){
                ans[pos]=curr;
                pos+=2;
            }
            else{
                ans[neg]=curr;
                neg+=2;
            }
        }
        return ans;
        
    }
};