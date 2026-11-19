class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookie) {
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        int child=0;
        int j=0;
        for(int i=0;i<cookie.size();i++){
            if(j==greed.size()){
                break;
            }
            if(cookie[i] >= greed[j]){
                child++;
                j++;
            }
        }
        return child;
    }
};