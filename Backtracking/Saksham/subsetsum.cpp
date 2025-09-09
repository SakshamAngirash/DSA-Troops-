// Using an extra DS : temp O(n*2^n)
// usign running_sum : O(2^n)

class Solution {
  public:
    void check(int idx,vector<int>&v,int running_sum,vector<int>&result)
    {
      if(idx>=v.size())
      {
        result.push_back(running_sum); 
        return;
      }
      //include
      check(idx+1,v,running_sum+v[idx],result); 
      //exclude
      check(idx+1,v,running_sum,result); 
    }
    vector<int> subsetSums(vector<int>& nums) {
        //your code goes here
        sort(nums.begin(),nums.end()); 
        vector<int> result; 
        check(0,nums,0,result); 
        return result;
    }
};