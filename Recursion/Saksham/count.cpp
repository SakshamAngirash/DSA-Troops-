class Solution{
    public: 

    int subseq(int idx, vector<int> &nums, int curr_sum , int k)
    {
        if(idx==nums.size())
        {
            if(curr_sum==k) return 1; 
            return 0; 
        }
        curr_sum+=nums[idx]; 
        int l = subseq(idx+1,nums,curr_sum,k); 

        curr_sum-=nums[idx]; 
        int r = subseq(idx+1,nums,curr_sum,k); 
        return l+r;
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here 
        return subseq(0,nums,0,k); 
        // idx , nums , temp , curr_sum, desired_sum , count 

    }
};