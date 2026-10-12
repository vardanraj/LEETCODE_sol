#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitCount(32, 0);

        
        for (int x : nums) {
            for (int b = 0; b < 32; b++) {
                if (x & (1 << b)) bitCount[b]++;
            }
        }

        
        vector<long long> constructed;
        for (int i = 0; i < n; i++) {
            long long val = 0;
            for (int b = 0; b < 32; b++) {
                if (bitCount[b] > 0) {
                    val |= (1LL << b);
                    bitCount[b]--;
                }
            }
            constructed.push_back(val);
        }

       
        sort(constructed.rbegin(), constructed.rend());

        
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + constructed[i] * constructed[i]) % MOD;
        }
        return (int)ans;
    }
};
