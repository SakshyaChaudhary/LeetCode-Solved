class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenPtr=0;
        int oddPtr=1;
        while(evenPtr!=nums.size()){
            if(nums[evenPtr]%2==0){
                evenPtr+=2;
            }
            if(nums[oddPtr]%2!=0){
                oddPtr+=2;
            }
            if(evenPtr>=nums.size() || oddPtr>nums.size()){
                break;
            }
            if( (nums[oddPtr]%2==0) && (nums[evenPtr]%2!=0) ){
                swap(nums[oddPtr],nums[evenPtr]);
            }
        }
        return nums;
        
    }
};