class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            //Not able to Remove All K elements.
            st.pop();
            k--;      
        }
        if(st.empty()){
            return "0";
        }
        string ans="";
        while(!st.empty()){
            //Put ans into string but dont Reverse to Solve leading zero
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        //Reverse a string
        reverse(ans.begin(), ans.end());
        if(ans.size()==0){
            return "0";
        }
        return ans;            
    }
};