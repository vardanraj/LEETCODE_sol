class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;
        for(auto c: nums) sq.push_back(1LL * c * c);
        
        sort(sq.begin(),sq.end());

        long long ans =0;
        int k = sq.size()/2;

        for(int i = 0; i <k; i++) ans -= sq[i];
        for(int i = k; i <sq.size(); i++) ans += sq[i];
        return ans;
    }
};