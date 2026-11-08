class Solution {
public:
    int countEven(int num) {
        int sum=num/2;
        if(num%2==1){
            return sum;
        }
        sum=sum-1;
        int evenSum=0;
        int temp=num;
        while(temp!=0){
            int digit=temp%10;
            temp=temp/10;
            evenSum+=digit;
        }

        return evenSum%2==0?sum+1:sum;        
    }
};