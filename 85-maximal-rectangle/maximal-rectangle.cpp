class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1'){
                    sum++;
                }
                else{
                    sum=0;
                }
                preSum[i][j]=sum;
            }
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(Histo(preSum[i]),maxArea);
        }
        return maxArea;        
    }
    int Histo(vector<int>& nums){
        stack<int> st;
        int maxArea=0;
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                int element=nums[st.top()];
                st.pop();
                int nextSmall=i;
                int prevSmall=st.empty()?-1:st.top();
                int currArea=element*(nextSmall-prevSmall-1);
                maxArea=max(maxArea,currArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=nums[st.top()];
            st.pop();
            int nextSmall=nums.size();
            int prevSmall=st.empty()?-1:st.top();
            int currArea=element*(nextSmall-prevSmall-1);
            maxArea=max(maxArea,currArea);
        }
        return maxArea;
    }
};