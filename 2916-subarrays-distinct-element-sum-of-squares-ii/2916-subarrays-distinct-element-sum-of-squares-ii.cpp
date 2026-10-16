#include <vector>
#include <cstring>

using namespace std;

class Solution {
    static const int B = 320; 
    long long arr[100005], block_sum[320], block_lazy[320];
    int last_pos[100005];
    const int MOD = 1e9 + 7;

    long long query_and_add(int l, int r) {
        long long sum_c = 0;
        int b_l = l / B, b_r = r / B;

        if (b_l == b_r) {
            for (int i = l; i <= r; ++i) {
                sum_c += arr[i] + block_lazy[b_l];
                arr[i]++;
                block_sum[b_l]++;
            }
        } else {
            for (int i = l, end = (b_l + 1) * B - 1; i <= end; ++i) {
                sum_c += arr[i] + block_lazy[b_l];
                arr[i]++;
                block_sum[b_l]++;
            }
            for (int b = b_l + 1; b < b_r; ++b) {
                sum_c += block_sum[b] + block_lazy[b] * B;
                block_lazy[b]++;
            }
            for (int i = b_r * B; i <= r; ++i) {
                sum_c += arr[i] + block_lazy[b_r];
                arr[i]++;
                block_sum[b_r]++;
            }
        }
        return sum_c % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        memset(arr, 0, sizeof(long long) * n);
        memset(block_sum, 0, sizeof(block_sum));
        memset(block_lazy, 0, sizeof(block_lazy));
        memset(last_pos, -1, sizeof(last_pos));

        long long total_ans = 0, cur_s2 = 0;

        for (int r = 0; r < n; ++r) {
            int p = last_pos[nums[r]];
            long long sum_c = query_and_add(p + 1, r);
            long long len = r - p;

            cur_s2 = (cur_s2 + 2 * sum_c + len) % MOD;
            total_ans = (total_ans + cur_s2) % MOD;
            last_pos[nums[r]] = r;
        }
        return total_ans;
    }
};