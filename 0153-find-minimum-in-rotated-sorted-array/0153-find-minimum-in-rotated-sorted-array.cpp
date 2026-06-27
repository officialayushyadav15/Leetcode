class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int top=0;
        int btm=n-1;
        while(top<btm){
            int mid = (top+btm)/2;
            if(nums[btm]<nums[mid]){
                top=mid+1;
            }
            else{
                btm = mid;
            }
        }
        return nums[top];
    }
};