class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(char ch:s){
            int temp=int(ch-'a')+1;
            sum += temp / 10 + temp % 10;
        }
        k--;
        while(k>0){
            int temp=sum;
            sum=0;
            while(temp!=0){
                sum+=temp%10;
                temp=temp/10;
            }
            k--;
        }
        return sum;
        
    }
};