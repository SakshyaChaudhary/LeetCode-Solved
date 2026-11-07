class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n+1,0);
        for(int i=0;i<trust.size();i++){
            score[trust[i][0]]--;
            score[trust[i][1]]++;
        }
        for(int i=1;i<score.size();i++){
            if(score[i]==n-1){ //Judge dont Trust Himself so -1
                return i;
            }
        }
        return -1;
        
    }
};