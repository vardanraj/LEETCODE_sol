#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        
        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d != n / d) divisors.push_back(n / d);
            }
        }

        int ans = 0;
        for (int k : divisors) {
            bool ok = true;
            for (int i = 0; i < n; i += k) {
                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                vector<int> target(sorted.begin() + i, sorted.begin() + i + k);

                
                vector<int> doubled = block;
                doubled.insert(doubled.end(), block.begin(), block.end());

               
                bool found = false;
                for (int j = 0; j < k; j++) {
                    if (equal(target.begin(), target.end(), doubled.begin() + j)) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans += k;
        }
        return ans;
    }
};
