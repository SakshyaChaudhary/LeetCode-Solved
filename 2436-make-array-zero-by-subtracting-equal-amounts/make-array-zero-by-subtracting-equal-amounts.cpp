class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op=0;
        for(int i=0;i<nums.size();i++){
            //Find Min
            int x=110;
            for(int j=0;j<nums.size();j++){
                if(nums[j]!=0 && nums[j]<x){
                    x=nums[j];
                }
            }
            if(x==110){
                break;
            }
            //Sub Min
            for(int j=0;j<nums.size();j++){
                if(nums[j]!=0){
                    nums[j]=nums[j]-x;
                }
            }
            op++;
        }
        return op;
        
    }
};