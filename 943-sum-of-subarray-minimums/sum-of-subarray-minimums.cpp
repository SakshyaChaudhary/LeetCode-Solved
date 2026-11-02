class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //Using Next Smaller and Prev Smaller Equal element
        // Use Index Instead of Value
        int n=arr.size();
        vector<int> NSE(n);
        vector<int> PSEE(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            NSE[i]=st.empty()?n:st.top();
            st.push(i);
        }
        stack<int> st2;
        for(int i=0;i<n;i++){
            while(!st2.empty() && arr[st2.top()]>arr[i]){
                st2.pop();
            }
            PSEE[i]=st2.empty()?-1:st2.top();
            st2.push(i);
        }
        int sum=0;
        int mod=(int) 1e9+7;
        for(int i=0;i<n;i++){
            int left=i-PSEE[i];
            int right=NSE[i]-i;
            sum=(sum+(left*right *1LL* arr[i]))%mod;
        }
        return sum;        
    }
};