class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first=0;
        int sec=0;
        while(sec<nums.size()){
            if(nums[sec]==val){
                sec++;
            }
            else{
                nums[first]=nums[sec];
                first++;
                sec++;
            }
        }
        return first;
    }
};