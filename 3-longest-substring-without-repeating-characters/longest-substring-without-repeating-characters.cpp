
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> Hash(256,-1);
        int left = 0;
        int maxLen=0;
        for(int right=0;right<s.size();right++){
            int ch=s[right];
            if(Hash[ch]<left){
                Hash[ch]=right;
            }
            else{
                left=Hash[ch]+1;
                Hash[ch]=right;
            }
            int Len=right-left+1;
            maxLen=max(maxLen,Len);
        }
        return maxLen;
    }
};
