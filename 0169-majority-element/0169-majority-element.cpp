class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n,c,el;
	n=nums.size();
	c=0;
	for(int i=0;i<n;i++){
		if(c==0){
			el=nums[i];
			c++;
		}
		else if(nums[i]==el){
			c++;
		}
		else{
			c--;
		}
		
	}
	
	return el;  
    }
};