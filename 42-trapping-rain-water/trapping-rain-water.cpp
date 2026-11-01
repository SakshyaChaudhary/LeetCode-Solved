class Solution {
public:
    int trap(vector<int>& height) {
        // O(N) Space and O(3N) Time Approch-
        // Prefix and Suffix Both with O(2N)
        // and Only Suffix and maintain leftMax for O(N) Space

        //2 pointer approch- O(1) Space and O(N) Time-
        int leftMax=0,rightMax=0,total=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]<leftMax){
                    total+=leftMax-height[left];
                }
                else{
                    leftMax=height[left];
                }
                left++;
            }
            else{
                if(height[right]<rightMax){
                    total+=rightMax-height[right];
                }
                else{
                    rightMax=height[right];
                }
                right--;
            }
        }
        return total;        
    }
};