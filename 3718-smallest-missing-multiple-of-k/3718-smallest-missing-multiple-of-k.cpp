class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int c=1;
        while(true){
            int t = k*c;
            if(find(nums.begin(), nums.end(),t) != nums.end()){
                c++;
            }
            else{
                return t;
            }
        }
        return 0;
    }
};