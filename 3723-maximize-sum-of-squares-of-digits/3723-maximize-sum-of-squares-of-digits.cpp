class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum> 9*num) return ""; // edge vala case

        string ans ="";
        for (int i =0; i<num; i++){
            int digit =  min(9,sum);
            ans.push_back('0'+ digit);// kyoki ye string hai is liye isse add kra hai taki int can be converted directly to string
            sum -=digit;
            
        }
        return ans;
    }
};