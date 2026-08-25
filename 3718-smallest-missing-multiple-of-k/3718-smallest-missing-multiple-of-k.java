class Solution {
    public int missingMultiple(int[] nums, int k) {
        int[] arr = new int[101];
        for(int i=0;i<nums.length;i++){
            arr[nums[i]-1]=nums[i];
        }
        int i=0;
        for(i=k-1;i<101;i=i+k){
            if(arr[i]==0){
                return i+1;
            }
        }
        return i+1;
    }
}