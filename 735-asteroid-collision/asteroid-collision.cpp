class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> ans; //Use it as Stack using back(), push_back(),popback(); 
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                ans.push_back(asteroids[i]);
            }
            else{
                int ab=abs(asteroids[i]);
                while(ans.size()!=0 && ans.back()>0 && ans.back()<ab){
                    ans.pop_back();
                }
                if(ans.size()!=0 && ans.back()==ab){
                    ans.pop_back();
                }
                else if(ans.size()==0 || ans.back()<0){ //Push if not Collide
                    ans.push_back(asteroids[i]);
                }

            }
        }
        return ans;
        
    }
};