class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> Next(n);
        vector<int> PrevEq(n);
        stack<int> st;
        long long maxSubSum=0;
        long long minSubSum=0;
        //maxSubArray -largest
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            Next[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            PrevEq[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            int left=i-PrevEq[i];
            int right=Next[i]-i;
            maxSubSum+=left*right* 1LL *nums[i];
        }
        
        //minSubArray- Smallest
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            Next[i]=st.empty()?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            PrevEq[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            int left=i-PrevEq[i];
            int right=Next[i]-i;
            minSubSum+=left*right*1LL*nums[i];
        }
        return maxSubSum-minSubSum;
    }
};