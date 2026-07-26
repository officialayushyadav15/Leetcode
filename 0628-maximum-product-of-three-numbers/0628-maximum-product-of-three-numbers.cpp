class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int value1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int value2 = nums[nums.size() - 3] * nums[nums.size() - 2] * nums[nums.size() - 1];

        if (value1 > value2)
            return value1;

        return value2;
    }
};