class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> mpp;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else if(nums2[i]<st.top()){
                mpp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && nums2[i]>st.top()){
                    st.pop();
                }
                if(st.empty()){
                    mpp[nums2[i]]=-1;
                    st.push(nums2[i]);
                }
                else{
                    mpp[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }

            }
        }
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;        
    }
};