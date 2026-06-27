class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, res = 0, mod = 1e9 + 7;
        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + pow2[r - l]) % mod;
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
