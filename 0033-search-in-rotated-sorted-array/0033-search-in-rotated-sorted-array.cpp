class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = high + (low - high) / 2;
            if (nums[mid] == target)
                return mid;
            else if(nums[low] <= nums[mid]){ //  front part sorted
                if(nums[low] <= target and target < nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{ // back part sorted
                if(nums[high]>=target and target > nums[mid]){
                    low = mid+1;
                }
                else high = mid-1;
            }

        }
        return -1;
    }
};
