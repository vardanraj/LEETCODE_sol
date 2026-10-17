#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>,int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }
        sort(arr.begin(), arr.end());

        vector<bool> vis(n,false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || arr[i].second == i) continue;
            int cycle = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = arr[j].second;
                cycle++;
            }
            swaps += cycle - 1;
        }
        return swaps;
    }
};
